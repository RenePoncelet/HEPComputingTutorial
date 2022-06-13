// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"

namespace Rivet {


  /// @brief Add a short analysis description here
  class TUTORIAL_TTBAR_0 : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(TUTORIAL_TTBAR_0);


    /// @name Analysis methods
    //@{

    /// Book histograms and initialise projections before the run
    void init() {
      // Declare projection
      FinalState fs(Cuts::OPEN);
      declare(fs,"fs");

      // Book histograms
      // specify custom binning
    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // Retrieve fs particles
      vector<Particle> fsparticles = apply<FinalState>(event, "fs").particles();

      MSG_INFO("This event contains the following final state particles:");
      for (auto &p : fsparticles)
        {
          MSG_INFO("PID: " << p.pid() << " p = " << p.momentum());
        }
    }

    /// Normalise histograms etc., after the run
    void finalize() {

    }

    //@}


  };


  DECLARE_RIVET_PLUGIN(TUTORIAL_TTBAR_0);

}
