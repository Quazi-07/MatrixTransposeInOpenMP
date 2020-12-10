#!/bin/bash -l
#-----------------------------------
# hw3.slurm
#
# Submit: 
#   sbatch hw3.slurm
#
# Check status:
#   squeue | grep [userid]
#   squeue -u [userid]
#   squeue -j [jobid]
#-----------------------------------

#SBATCH --job-name=hw3
#SBATCH --partition=hodor-cpu
#SBATCH --export=ALL
#SBATCH --exclusive

# Sets the maximum time the job can run (hh:mm:ss).
#SBATCH --time=00:02:00


# Sets the output files.
#SBATCH --output=./hw3.hodor-cpu.%j.txt

# Job events (mail-type): begin, end, fail, all. 
#SBATCH --mail-type=fail
#SBATCH --mail-user=mdsaifur.rahman.1@und.edu

module list
echo ""

# run with 4 command line arguments 
./hw3.o 2000 5000 n 4  
