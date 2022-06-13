#!/bin/bash

lpath=$(pwd)"/HEPSoftware/install"

export PATH=$PATH:$lpath"/bin":$lpath"/share"
export CPATH=$CPATH:$lpath"/include"
export LIBRARY_PATH=$LIBRARY_PATH:$lpath"/lib":$lpath"/lib64"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$lpath"/lib":$lpath"/lib64"
