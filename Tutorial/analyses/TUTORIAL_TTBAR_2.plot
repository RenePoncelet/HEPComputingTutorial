# BEGIN PLOT /TUTORIAL_TTBAR_2/.*
LegendAlign=r
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jet.?_[1234]_pT
XLabel=$p_\perp$ [GeV]
YLabel=$\mathrm{d}\sigma/\mathrm{d}p_\perp$ [pb GeV$^{-1}$]
LogX=1
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jet_mult
Title=Jet multiplicity
XLabel=$N_\text{jets}$
YLabel=$\mathrm{d}\sigma/\mathrm{d}N_\text{jets}$ [pb]
LogY=0
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jet_1_pT
Title=Transverse momentum distribution for jet 1
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jet_2_pT
Title=Transverse momentum distribution for jet 2
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jet_3_pT
Title=Transverse momentum distribution for jet 3
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jet_4_pT
Title=Transverse momentum distribution for jet 4
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jet_HT
Title=$H_\text{T}$ distribution for all jets
XLabel=$H_\text{T}$ [GeV]
YLabel=$\mathrm{d}\sigma/\mathrm{d}H_T$ [pb GeV$^{-1}$]
LogX=1
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jets_mjj
Title=Dijet invariant mass spectrum
XLabel=$m_{jj}$ [GeV]
YLabel=$\text{d}\sigma/\text{d}m_{jj}$ [pb GeV$^{-1}$]
LegendAlign=r
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jetb_1_pT
Title=Transverse momentum distribution for $b$-jet 1
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jetb_2_pT
Title=Transverse momentum distribution for $b$-jet 2
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jetl_1_pT
Title=Transverse momentum distribution for light jet 1
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*jetl_2_pT
Title=Transverse momentum distribution for light jet 2
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*W_mass
Title=Mass distribution for $W$ bosons
XLabel=$W$-candiate $m_\text{inv}$ [GeV]
YLabel=$\mathrm{d}\sigma/\mathrm{d}m_\text{inv}$ [pb GeV$^{-1}$]
LogY=0
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*t_mass
Title=Mass distribution for reconstructed top
XLabel=$m_{q\bar{q}b}$ [GeV]
YLabel=$\mathrm{d}\sigma/\mathrm{d}m_{q\bar{q}b}$ [pb GeV$^{-1}$]
LogY=0
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*t_mass_W_cut
Title=Mass distribution for reconstructed top after $m_W$ cut
XLabel=$m_{q\bar{q}b}$ [GeV]
YLabel=$\mathrm{d}\sigma/\mathrm{d}m_{q\bar{q}b}$ [pb GeV$^{-1}$]
LogY=0
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*_mass
XLabel=$m$ [GeV]
YLabel=$\mathrm{d}\sigma/\mathrm{d}m$ [pb GeV$^{-1}$]
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*_dR
XLabel=$\Delta R$
YLabel=$\mathrm{d}\sigma/\mathrm{d}\Delta R$ [pb]
LogY=0
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*_deta
XLabel=$\Delta \eta$
YLabel=$\mathrm{d}\sigma/\mathrm{d}\Delta \eta$ [pb]
LogY=0
# END PLOT

# BEGIN PLOT /TUTORIAL_TTBAR_2/.*_dphi
XLabel=$\Delta \phi$
YLabel=$\mathrm{d}\sigma/\mathrm{d}\Delta \phi$ [pb]
LogY=0
# END PLOT

# BEGIN SPECIAL /TUTORIAL_TTBAR_2/allhad_ allHad
Location=MainPlot
\rput[tr]{0}(1.,1.1){$(N_\ell = 0)$}
# END SPECIAL

# BEGIN SPECIAL /TUTORIAL_TTBAR_2/onelep_ oneLep
Location=MainPlot
\rput[tr]{0}(1.,1.1){$(N_\ell = 1)$}
# END SPECIAL

# BEGIN SPECIAL /TUTORIAL_TTBAR_2/twolep_ twoLep
Location=MainPlot
\rput[tr]{0}(1.,1.1){$(N_\ell = 2)$}
# END SPECIAL

# BEGIN SPECIAL /TUTORIAL_TTBAR_2/anylep_ anyLep
Location=MainPlot
\rput[tr]{0}(1.,1.1){$(N_\ell \geq 1)$}
# END SPECIAL
