// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/PartonicTops.hh"

namespace Rivet {


  /// @brief Add a short analysis description here
  class TUTORIAL_TTBAR_1 : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(TUTORIAL_TTBAR_1);


    /// @name Analysis methods
    //@{

    /// Book histograms and initialise projections before the run
    void init() {
      // Declare projection
      PartonicTops tops(Cuts::OPEN);
      declare(tops,"tops");

      // Book histograms
      // specify custom binning pT
      book(_h["pTtop"], "pTtop1", 25, 0.0, 1000.0);
      book(_h["pTatop"], "pTatop1", 25, 0.0, 1000.0);
      book(_h["pTtt"], "pTtt", 25, 0.0, 500.0);
    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // Retrieve top-quarks
      vector<Particle> tops = apply<PartonicTops>(event, "tops").particles();

      unsigned idtop = 0, idatop = 0;
      if (tops[0].pid() == 6)
        {
          idtop = 0;
	  idatop = 1;
        }
      else
        {
          idtop = 1;
	  idatop = 0;
        }
      // Fill histogram with top pT
      _h["pTtop"]->fill(tops[idtop].pT()/GeV);
      _h["pTatop"]->fill(tops[idatop].pT()/GeV);
      _h["pTtt"]->fill((tops[0].momentum()+tops[1].momentum()).pT()/GeV);

    }

    /// Normalise histograms etc., after the run
    void finalize() {

      normalize(_h["pTtop"]); // normalize to unity
      normalize(_h["pTatop"]); // normalize to unity
      normalize(_h["pTtt"]); // normalize to unity

    }

    //@}


    /// @name Histograms
    //@{
    map<string, Histo1DPtr> _h;
    //@}


  };


  DECLARE_RIVET_PLUGIN(TUTORIAL_TTBAR_1);

}
