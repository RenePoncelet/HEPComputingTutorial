#!/bin/bash

# Dependencies:
 sudo apt install gcc g++ python-dev zlib1g-dev gfortran git autoconf automake texlive texlive-pstricks imagemagick-6.q16hdri libtool


#### first run the rivet bootstrap script which installs most of the software
cd build
mkdir rivet
cd rivet
wget https://gitlab.com/hepcedar/rivetbootstrap/raw/3.1.0/rivet-bootstrap
chmod +x rivet-bootstrap
INSTALL_PREFIX=/home/tutorial/HEPSoftware/install ./rivet-bootstrap

#### install LHAPDF
cd /home/tutorial/HEPSoftware/tarballs
wget https://lhapdf.hepforge.org/downloads/LHAPDF-6.2.3.tar.gz
cd /home/tutorial/HEPSoftware/build
tar -xf ../tarballs/LHAPDF-6.2.3.tar.gz
cd LHAPDF-6.2.3
./configure --prefix=/home/tutorial/HEPSoftware/install
make
make install
#### install NNPDF 31 as an example
wget http://lhapdfsets.web.cern.ch/lhapdfsets/current/NNPDF31_nnlo_as_0118.tar.gz -O- | tar xz -C /home/tutorial/HEPSoftware/install/share/LHAPDF

#### install OpenLoops
cd /home/tutorial/HEPSoftware/build
git clone https://gitlab.com/openloops/OpenLoops.git
cd OpenLoops
./scons
./openloops libinstall pptt
# make lib public
ln -s ./lib/* /home/tutorial/HEPSoftware/install/lib/
ln -s ./include/* /home/tutorial/HEPSoftware/install/include/

#### install Sherpa
cd /home/tutorial/HEPSoftware/tarballs
wget https://sherpa.hepforge.org/downloads/SHERPA-MC-2.2.8.tar.gz
cd /home/tutorial/HEPSoftware/build
tar -xf ../tarballs/SHERPA-MC-2.2.8.tar.gz
cd SHERPA-MC-2.2.8
./configure 
