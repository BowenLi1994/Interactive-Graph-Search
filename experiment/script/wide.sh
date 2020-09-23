#!/bin/bash

../sequence ordered combine100 > ordered.result &
../sequence comprehensive combine100 1 1 0 1 > 0.result &
../sequence comprehensive combine100 1 1 0.5 1 > 0.5.result &
../sequence comprehensive combine100 1 1 1 1 > 1.result &
