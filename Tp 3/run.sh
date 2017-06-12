#!/bin/bash
STR="resultados.csv"
ARRAY=(1000 2000 5000 10000 50000 100000 500000)
TAM=7
NUM=30
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
	cd ShellSort/;
	for(( j=0; j<$TAM; j++)) do
		for(( i=0;i<$NUM;i++ )) do
			./shell ${ARRAY[j]}>> ../$STR;
		done
		echo "Shell - ${ARRAY[j]} - OK"
	done
		rm -rf ./shell *.o;
	cd ../MergeSort;
	for(( j=0; j<$TAM; j++)) do
		for(( i=0;i<$NUM;i++ )) do
			./mergesort ${ARRAY[j]}>> ../$STR;
		done
		echo "Merge - ${ARRAY[j]} - OK"
	done
		rm -rf ./mergesort *.o;
	cd ../Selection;
	for(( j=0; j<$TAM; j++)) do
		for(( i=0;i<$NUM;i++ )) do
			./selection ${ARRAY[j]}>> ../$STR;
		done
		echo "Selection - ${ARRAY[j]} - OK"
	done
		rm -rf ./selection *.o;
	cd ../QuickSort/Pivo_central;
	for(( j=0; j<$TAM; j++)) do
		for(( i=0;i<$NUM;i++ )) do
			./quick ${ARRAY[j]}>> ../$STR;
		done
		echo "Quick 1 - ${ARRAY[j]} - OK"
	done
		rm -rf ./quick *.o;
	cd ../Pivo_mediana;
	for(( j=0; j<$TAM; j++)) do
		for(( i=0;i<$NUM;i++ )) do
			./quick ${ARRAY[j]}>> ../$STR;
		done
		echo "Quick 1 - ${ARRAY[j]} - OK"
	done
		rm -rf ./quick *.o;
	cd ../QuickParcial;
	for(( j=0; j<$TAM; j++)) do
		for(( i=0;i<$NUM;i++ )) do
			./quick ${ARRAY[j]}>> ../$STR;
		done
		echo "Quick 1 - ${ARRAY[j]} - OK"
	done
		rm -rf ./quick *.o;
	cd ../../Insertion;
	for(( j=0; j<$TAM; j++)) do
		for(( i=0;i<$NUM;i++ )) do
			./insertion ${ARRAY[j]}>> ../$STR;
		done
		echo "Insertion - ${ARRAY[j]} - OK"
	done
		rm -rf ./insertion *.o;
	cd ../
done



