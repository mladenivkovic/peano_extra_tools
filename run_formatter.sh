#!/bin/bash


#--------------------------------------------------------
# A script to run the format.py script in the intended
# way for this repository such that format.py can remain
# nearly unmodified from the one in the actual Peano
# repository
#--------------------------------------------------------


python3 ./format.py --verbose --files `git ls-files`
