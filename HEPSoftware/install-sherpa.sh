#!/bin/bash

dir=$(pwd)


echo '#############################'
echo 'Install HEPSoftware to : '$dir
echo '#############################'
echo ''

##### install Sherpa
cd $dir/tarballs
wget https://sherpa.hepforge.org/downloads/SHERPA-MC-2.2.8.tar.gz
cd $dir/build
tar -xf ../tarballs/SHERPA-MC-2.2.8.tar.gz
cd SHERPA-MC-2.2.8
./configure --prefix=$dir/install --with-sqlite3=install --enable-hepmc2=$dir/install --enable-lhapdf=$dir/install --enable-rivet=$dir/install --enable-openloops=$dir/install
make
make install
