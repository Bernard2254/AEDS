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
		printf "Shell - ${ARRAY[j]}\n\n"
		for(( i=0;i<$NUM;i++ )) do
			printf "Shell - $((i+1))/$NUM - "
			./shell ${ARRAY[j]}>> ../$STR;
			echo "OK"
		done
		printf "Shell - ${ARRAY[j]} - OK\n\n"
	done
		rm -rf ./shell *.o;
	cd ../MergeSort;
	for(( j=0; j<$TAM; j++)) do
		printf "Merge - ${ARRAY[j]}\n\n"
		for(( i=0;i<$NUM;i++ )) do
			printf "Merge - $((i+1))/$NUM - "
			./mergesort ${ARRAY[j]}>> ../$STR;
			echo "OK"
		done
		printf "Merge - ${ARRAY[j]} - OK\n\n"
	done
		rm -rf ./mergesort *.o;
	cd ../QuickSort/Pivo_central;
	for(( j=0; j<$TAM; j++)) do
		printf "Quick 1 - ${ARRAY[j]}\n\n"
		for(( i=0;i<$NUM;i++ )) do
			printf "Quick 1 - $((i+1))/$NUM - "
			./quick ${ARRAY[j]}>> ../../$STR;
			echo "OK"
		done
		printf "Quick 1 - ${ARRAY[j]} - OK\n\n"
	done
		rm -rf ./quick *.o;
	cd ../Pivo_mediana;
	for(( j=0; j<$TAM; j++)) do
		printf "Quick 2 - ${ARRAY[j]}\n\n"
		for(( i=0;i<$NUM;i++ )) do
			printf "Quick 2 - $((i+1))/$NUM - "
			./quick ${ARRAY[j]}>> ../../$STR;
			echo "OK"
		done
		printf "Quick 2 - ${ARRAY[j]} - OK\n\n"
	done
		rm -rf ./quick *.o;
	cd ../QuickParcial;
	for(( j=0; j<$TAM; j++)) do
		printf "Quick 3 - ${ARRAY[j]}\n\n"
		for(( i=0;i<$NUM;i++ )) do
			printf "Quick 3 - $((i+1))/$NUM - "
			./quick ${ARRAY[j]}>> ../../$STR;
			echo "OK"
		done
		printf "Quick 3 - ${ARRAY[j]} - OK\n\n"
	done
		rm -rf ./quick *.o;
	cd ../../Insertion;
	for(( j=0; j<$TAM; j++)) do
		printf "Insertion - ${ARRAY[j]}\n\n"
		for(( i=0;i<$NUM;i++ )) do
			printf "Insertion - $((i+1))/$NUM - "
			./insertion ${ARRAY[j]}>> ../$STR;
			echo "OK"
		done
		printf "Insertion - ${ARRAY[j]} - OK\n\n"
	done
		rm -rf ./insertion *.o;
	cd ../Selection;
	for(( j=0; j<$TAM; j++)) do
		printf "Selection - ${ARRAY[j]}\n\n"
		for(( i=0;i<$NUM;i++ )) do
			printf "Selection - $((i+1))/$NUM - "
			./selection ${ARRAY[j]}>> ../$STR;
			echo "OK"
		done
		printf "Selection - ${ARRAY[j]} - OK\n\n"
	done
		rm -rf ./selection *.o;


