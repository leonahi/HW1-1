#!/bin/bash

clear

name=$(uname -s)
hardware=$(uname -m)
mem=$(free -omt)
cpu=$(cat /proc/cpuinfo | grep 'cpu MHz' | sed 's/cpu MHz//')
cpumodel=$(cat /proc/cpuinfo | grep 'model name' | sed 's/model name//')

echo "System Information" 
echo "OS Type                 : $name"
echo "Hardware Architecture   : $hardware"
echo "CPU Model         $cpumodel"
echo "CPU Speed   $cpu MHz"
echo "System Memory in MB"
echo "$mem"

touch hw1.txt

declare -a SIZES=('100' '500' '1000' '2000');
echo "Executing SERIAl"
for i in "${SIZES[@]}"
do	
echo  "Computing Size $i....."
./serial $i | cat >> hw1.txt
done
echo "Done SERIAL"
gnuplot < serial_plot


declare -a THREADS=('2' '4' '8' '16');
echo "Executing OPENMP"
for i in "${SIZES[@]}"
do
	for j in "${THREADS[@]}"
	do
	echo "Computing for Size $i using $j threads"
	./openmp $i $j | cat >> hw1.txt
done
done
echo "Done OPENMP"
gnuplot < openmp_plot


echo "Executing MPI"
for i in "${SIZES[@]}"
do
	for j in "${THREADS[@]}"
	do
	echo "Computing for Size $i using $j threads"
	echo -n "$j " >> hw1.txt 
	mpiexec -np $j mpi $i | cat >> hw1.txt
done
done
echo "Done MPI"
gnuplot < mpi_plot

rm hw1.txt
