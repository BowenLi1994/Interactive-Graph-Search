#!/bin/bash
./sequence baseline combine10000 > wide10000_baseline.result
./sequence ordered combine10000 > wide10000_ordered.result
./sequence sibling combine10000 3 > wide10000_sibling.result
./sequence outdegree combine10000 3 > wide10000_outdegree.result
./sequence comprehensive combine10000 10 >wide10000_outdegree.result
