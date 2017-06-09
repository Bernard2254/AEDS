#!/bin/bash
STR="resultados.csv"
ARRAY=(10 20 50 100 200 500 1000 5000)
if [ -e $STR ]; then
	rm -rf $STR;
fi
cd ShellSort/;
	make bash;
cd ../MergeSort;
	make bash;
cd ../Selection;
	make bash;
cd ../QuickSort/Pivo_central;
	make bash;
cd ../Pivo_mediana;
	make bash;
cd ../QuickParcial;
	make bash;
cd ../../Insertion;
	make bash;
cd ../
for(( j=0; j<8; j++)) do
	cd ShellSort/;
	for(( i=0;i<30;i++ )) do
		./shell ${ARRAY[j]}>> ../$STR;
	done
	if [ $j = 7 ]; then
		rm -rf ./shell *.o;
	fi
	cd ../MergeSort;
	for(( i=0;i<30;i++ )) do
	        ./mergesort ${ARRAY[j]} >> ../$STR;
	done
	if [ $j = 7 ]; then
		rm -rf ./mergesort *.o;
	fi
	cd ../Selection;
	for(( i=0;i<30;i++ )) do 
	        ./selection ${ARRAY[j]}>> ../$STR;
	done
	if [ $j = 7 ]; then
		rm -rf ./selection *.o;
	fi
	cd ../QuickSort/Pivo_central;
	for(( i=0;i<30;i++ )) do 
	        ./quick ${ARRAY[j]}>> ../../$STR;
	done
	if [ $j = 7 ]; then
		rm -rf ./quick *.o;
	fi
	cd ../Pivo_mediana;
	for(( i=0;i<30;i++ )) do 
	        ./quick ${ARRAY[j]}>> ../../$STR;
	done
	if [ $j = 7 ]; then
		rm -rf ./quick *.o;
	fi
	cd ../QuickParcial;
	for(( i=0;i<30;i++ )) do 
	        ./quick ${ARRAY[j]}>> ../../$STR ;
	done
	if [ $j = 7 ]; then
		rm -rf ./quick *.o;
	fi
	cd ../../Insertion;
	for(( i=0;i<30;i++ )) do 
	        ./insertion ${ARRAY[j]}>> ../$STR;
	done
	if [ $j = 7 ]; then
		rm -rf ./insertion *.o;
	fi
	cd ../
done



