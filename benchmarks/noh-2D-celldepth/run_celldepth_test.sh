#!/bin/bash

set -e

timing() {
    # Function to time the process.

errormsg='
    Usage: timing executable args
'

if [ "$#" -lt 1 ]; then
    echo "$errormsg"
    exit
fi

timeformat="----------------------------------------------------------------\n"
timeformat="$timeformat""stats for %C\n"
timeformat="$timeformat""AverageMem(kb),MaxMem(kb),WallTime(s),CPUTime(s),UserTime(s),CPUPercentage\n"
timeformat="$timeformat""%K,%M,%e,%S,%U,%P"

/usr/bin/time -f "$timeformat" "$@"
}



# Script to run experiment (Noh 2D)

# set threads number
export OMP_NUM_THREADS=4

# Parameters
# N_PART=32
# END_TIME=0.2
END_TIME=0.01 # 100 steps
TIMESTEP_SIZE=0.0001
CFL_FACTOR=0.2
PLOT_DELTA=0.01

for N_PART in 32 64; do
    for CELL_SIZE_MAX in 2 0.67 0.23; do
        for CELL_SIZE_MIN in 2 0.67 0.23 0.075 0.025; do

            if (( $(echo "$CELL_SIZE_MIN > $CELL_SIZE_MAX" |bc -l) )); then
                continue;
            fi

            # Run python script to generate the experiment
            echo COMPILING N_PART=$N_PART CELL_MAX=$CELL_SIZE_MAX CELL_MIN=$CELL_SIZE_MIN
            python3 noh.py -np $N_PART -et $END_TIME -dt $TIMESTEP_SIZE -cfl $CFL_FACTOR -plot $PLOT_DELTA --cell-size-max $CELL_SIZE_MAX --cell-size-min $CELL_SIZE_MIN > /dev/null

            SUFFIX="N$N_PART-$CELL_SIZE_MAX-$CELL_SIZE_MIN"
            mv noh2D noh2D-$SUFFIX
            OUTFILE=output_$SUFFIX.log

            echo RUNNING N_PART=$N_PART CELL_MAX=$CELL_SIZE_MAX CELL_MIN=$CELL_SIZE_MIN
            timing -o "$OUTFILE" -a ./noh2D-$SUFFIX.sh 2>&1 > "$OUTFILE"

            echo FINISHED N_PART=$N_PART CELL_MAX=$CELL_SIZE_MAX CELL_MIN=$CELL_SIZE_MIN
            tail -n 4 "$OUTFILE"

            exit

        done
    done
done


echo 'Done. Bye!'
