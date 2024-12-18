#!/bin/bash

set -e

# Function to time the process.
# Usage: timing `executable` `args`
timing() {

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
END_TIME=0.01 # 100 steps
TIMESTEP_SIZE=0.0001
CFL_FACTOR=0.2
PLOT_DELTA=0.01

# if "false", will skip compiling if exec already exists, and
# will skip running experiment if outputfile already exists
REDO="false"

for N_PART in 20 32; do
    for CELL_SIZE_MAX in 2 0.67 0.23; do
        for CELL_SIZE_MIN in 2 0.67 0.23 0.075 0.025; do

            if (( $(echo "$CELL_SIZE_MIN > $CELL_SIZE_MAX" |bc -l) )); then
                continue;
            fi

            SUFFIX="N$N_PART-$CELL_SIZE_MAX-$CELL_SIZE_MIN"
            OUTFILE=output_$SUFFIX.log
            EXEC=noh2D-$SUFFIX

            if [[ "$REDO" != "false" ]] || [[ ! -f "$EXEC" ]]; then

                # Run python script to generate the experiment
                echo COMPILING N_PART=$N_PART CELL_MAX=$CELL_SIZE_MAX CELL_MIN=$CELL_SIZE_MIN
                python3 noh.py -np $N_PART -et $END_TIME -dt $TIMESTEP_SIZE -cfl $CFL_FACTOR -plot $PLOT_DELTA --cell-size-max $CELL_SIZE_MAX --cell-size-min $CELL_SIZE_MIN > /dev/null
                # rename exec
                mv noh3D $EXEC
            fi

            if [[ "$REDO" != "false" ]] || [[ ! -f "$OUTFILE" ]]; then
                echo RUNNING N_PART=$N_PART CELL_MAX=$CELL_SIZE_MAX CELL_MIN=$CELL_SIZE_MIN

                timing -o "$OUTFILE" -a ./noh2D-$SUFFIX 2>&1 > "$OUTFILE"
                echo FINISHED N_PART=$N_PART CELL_MAX=$CELL_SIZE_MAX CELL_MIN=$CELL_SIZE_MIN
                tail -n 4 "$OUTFILE"

            else
                echo SKIPPING EXISTING RUN N_PART=$N_PART CELL_MAX=$CELL_SIZE_MAX CELL_MIN=$CELL_SIZE_MIN
            fi
        done
    done
done


echo 'Done. Bye!'
