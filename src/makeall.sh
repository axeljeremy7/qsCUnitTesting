#!/bin/bash

make clean

make gene
make geneo
make rungen

make -B test
make runtest

make -B output
make run
make run2

