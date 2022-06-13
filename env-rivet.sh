#!/bin/bash

lpath=$(pwd)"/HEPSoftware/install"

source $lpath"/rivetenv.sh"
export RIVET_ANALYSIS_PATH=$RIVET_ANALYSIS_PATH:$(pwd)/Tutorial/analyses/
