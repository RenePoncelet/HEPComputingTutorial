#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/VetoedFinalState.hh"
#include "Rivet/Projections/ChargedLeptons.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/AnalysisLoader.hh"

namespace Rivet {

  


  class TUTORIAL_TTBAR_2 : public Analysis {
  public:

    /// Minimal constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(TUTORIAL_TTBAR_2);


    /// @name Analysis methods
    //@{

    /// Set up projections and book histograms
    void init() {

      _mode = 1; string pre = "onelep_"; // default is single-lepton decay mode

      // A FinalState is used to select particles within |eta| < 4.2 and with pT
      // > 30 GeV, out of which the ChargedLeptons projection picks only the
      // electrons and muons, to be accessed later as "LFS".
      ChargedLeptons lfs(FinalState(Cuts::abseta < 4.2 && Cuts::pT > 30*GeV));
      declare(lfs, "LFS");

      // A second FinalState is used to select all particles in |eta| < 4.2,
      // with no pT cut. This is used to construct jets and measure missing
      // transverse energy.
      VetoedFinalState fs(FinalState(Cuts::abseta < 4.2));
      fs.addVetoOnThisFinalState(lfs);
      declare(FastJets(fs, FastJets::ANTIKT, 0.6), "Jets");
      declare(MissingMomentum(fs), "MissingET");

      // Booking of histograms
      book(_h["njets"], pre + "jet_mult", 11, -0.5, 10.5);
      //
      book(_h["jet_1_pT"], pre + "jet_1_pT", logspace(50, 20.0, 500.0));
      book(_h["jet_2_pT"], pre + "jet_2_pT", logspace(50, 20.0, 400.0));
      book(_h["jet_3_pT"], pre + "jet_3_pT", logspace(50, 20.0, 300.0));
      book(_h["jet_4_pT"], pre + "jet_4_pT", logspace(50, 20.0, 200.0));
      book(_h["jet_HT"],   pre + "jet_HT", logspace(50, 100.0, 2000.0));
      //
      book(_h["bjet_1_pT"], pre + "jetb_1_pT", logspace(50, 20.0, 400.0));
      book(_h["bjet_2_pT"], pre + "jetb_2_pT", logspace(50, 20.0, 300.0));
      //
      book(_h["ljet_1_pT"], pre + "jetl_1_pT", logspace(50, 20.0, 400.0));
      book(_h["ljet_2_pT"], pre + "jetl_2_pT", logspace(50, 20.0, 300.0));
      //
      book(_h["W_mass"], pre + "W_mass", 75, 30, 180);
      book(_h["t_mass"], pre + "t_mass", 150, 130, 430);
      book(_h["t_mass_W_cut"], pre + "t_mass_W_cut", 150, 130, 430);
      book(_h["jetb_1_W_dR"],  pre + "jetb_1_W_dR", 20, 0.0, 7.0);
      book(_h["jetb_1_W_deta"], pre + "jetb_1_W_deta", 20, 0.0, 7.0);
      book(_h["jetb_1_W_dphi"], pre + "jetb_1_W_dphi", 20, 0.0, M_PI);
      //
      book(_h["jetb_1_jetb_2_dR"],   pre + "jetb_1_jetb_2_dR", 20, 0.0, 7.0);
      book(_h["jetb_1_jetb_2_deta"], pre + "jetb_1_jetb_2_deta", 20, 0.0, 7.0);
      book(_h["jetb_1_jetb_2_dphi"], pre + "jetb_1_jetb_2_dphi", 20, 0.0, M_PI);
      book(_h["jetb_1_jetl_1_dR"],   pre + "jetb_1_jetl_1_dR", 20, 0.0, 7.0);
      book(_h["jetb_1_jetl_1_deta"], pre + "jetb_1_jetl_1_deta", 20, 0.0, 7.0);
      book(_h["jetb_1_jetl_1_dphi"], pre + "jetb_1_jetl_1_dphi", 20, 0.0, M_PI);
      book(_h["jetl_1_jetl_2_dR"],   pre + "jetl_1_jetl_2_dR", 20, 0.0, 7.0);
      book(_h["jetl_1_jetl_2_deta"], pre + "jetl_1_jetl_2_deta", 20, 0.0, 7.0);
      book(_h["jetl_1_jetl_2_dphi"], pre + "jetl_1_jetl_2_dphi", 20, 0.0, M_PI);
      
      book(_h["jetb_1_l_dR"],   pre + "jetb_1_l_dR", 20, 0.0, 7.0);
      book(_h["jetb_1_l_deta"], pre + "jetb_1_l_deta", 20, 0.0, 7.0);
      book(_h["jetb_1_l_dphi"], pre + "jetb_1_l_dphi", 20, 0.0, M_PI);
      book(_h["jetb_1_l_mass"], pre + "jetb_1_l_mass", 40, 0.0, 500.0);
    }


    void analyze(const Event& event) {
      const double weight = 1.0;

      // Use the "LFS" projection to require at least one hard charged
      // lepton. This is an experimental signature for the leptonically decaying
      // W. This helps to reduce pure QCD backgrounds.
      const ChargedLeptons& lfs = apply<ChargedLeptons>(event, "LFS");
      MSG_DEBUG("Charged lepton multiplicity = " << lfs.chargedLeptons().size());
      for (const Particle& lepton : lfs.chargedLeptons()) {
        MSG_DEBUG("Lepton pT = " << lepton.pT());
      }

      size_t nLeps = lfs.chargedLeptons().size();
      bool leptonMultiFail = nLeps != 1; // single lepton
      if (leptonMultiFail) {
        MSG_DEBUG("Event failed lepton multiplicity cut");
        vetoEvent;
      }

      // Use a missing ET cut to bias toward events with a hard neutrino from
      // the leptonically decaying W. This helps to reduce pure QCD backgrounds.
      // not applied in all-hadronic mode
      const Vector3& met = apply<MissingMomentum>(event, "MissingET").vectorMissingPt();
      MSG_DEBUG("Vector pT = " << met.mod() << " GeV");
      if ( met.mod() < 30*GeV) {
        MSG_DEBUG("Event failed missing ET cut");
        vetoEvent;
      }

      // Use the "Jets" projection to check how many jets with pT > 30 GeV there are
      // remove jets overlapping with any lepton (dR < 0.3)
      // cut on jet multiplicity depending on ttbar decay mode
      const FastJets& jetpro = apply<FastJets>(event, "Jets");
      const Jets jets = discardIfAnyDeltaRLess(jetpro.jetsByPt(30*GeV), lfs.chargedLeptons(), 0.3);

      if (jets.size() < 4)  vetoEvent; // single lepton

      // Fill histograms for inclusive jet kinematics 
      _h["njets"]->fill(jets.size(), weight);
      _h["jet_1_pT"]->fill(jets[0].pT()/GeV, weight);
      _h["jet_2_pT"]->fill(jets[1].pT()/GeV, weight);
      _h["jet_3_pT"]->fill(jets[2].pT()/GeV, weight);
      _h["jet_4_pT"]->fill(jets[3].pT()/GeV, weight);

      double ht = 0.0;
      for (const Jet& j : jets) { ht += j.pT(); }
      _h["jet_HT"]->fill(ht/GeV, weight);

      // Sort the jets into b-jets and light jets. We expect one hard b-jet from
      // each top decay, so our 4 hardest jets should include two b-jets. The
      // Jet::bTagged() method is equivalent to perfect experimental
      // b-tagging, in a generator-independent way.
      Jets bjets, ljets;
      for (const Jet& jet : jets) {
        if (jet.bTagged())  bjets += jet;
        else                ljets += jet;
      }
      MSG_DEBUG("Number of b-jets = " << bjets.size());
      MSG_DEBUG("Number of l-jets = " << ljets.size());
      if (bjets.size() != 2) {
        MSG_DEBUG("Event failed post-lepton-isolation b-tagging cut");
        vetoEvent;
      }
      if (_mode == 1 && ljets.size() < 2)  vetoEvent;

      // Plot the pTs of the identified jets.
      _h["bjet_1_pT"]->fill(bjets[0].pT(), weight);
      _h["bjet_2_pT"]->fill(bjets[1].pT(), weight);
      // need to check size to cater for dileptonic mode
      _h["ljet_1_pT"]->fill(ljets[0].pT(), weight);
      _h["ljet_2_pT"]->fill(ljets[1].pT(), weight);

      // Start your code here!!!

    }

    double findZcomponent(const FourMomentum& lepton, const Vector3& met) const {
      // estimate z-component of momentum given lepton 4-vector and MET 3-vector
      double pz_estimate;
      double m_W = 80.399*GeV;
      double k = (( sqr( m_W ) - sqr( lepton.mass() ) ) / 2 ) + (lepton.px() * met.x() + lepton.py() * met.y());
      double a = sqr ( lepton.E() )- sqr ( lepton.pz() );
      double b = -2*k*lepton.pz();
      double c = sqr( lepton.E() ) * sqr( met.perp() ) - sqr( k );
      double discriminant = sqr(b) - 4 * a * c;
      double quad[2] = { (- b - sqrt(discriminant)) / (2 * a), (- b + sqrt(discriminant)) / (2 * a) }; //two possible quadratic solns
      if (discriminant < 0)  pz_estimate = - b / (2 * a); //if the discriminant is negative
      else { //if the discriminant is greater than or equal to zero, take the soln with smallest absolute value
        double absquad[2];
        for (int n=0; n<2; ++n)  absquad[n] = fabs(quad[n]);
        if (absquad[0] < absquad[1])  pz_estimate = quad[0];
        else                          pz_estimate = quad[1];
      }
      return pz_estimate;
    }

    void finalize() {
      const double sf = crossSection() / sumOfWeights();
      for (auto hist : _h) { scale(hist.second, sf); }
    }

    //@}

  protected:

      size_t _mode;


  private:

    // @name Histogram data members
    //@{
    map<string, Histo1DPtr> _h;
    //@}

  };



  // The hook for the plugin system
  DECLARE_RIVET_PLUGIN(TUTORIAL_TTBAR_2);

}
