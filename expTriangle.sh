#!/bin/bash


declare -a arr=(
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_01.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_02.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_03.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_04.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_05.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_06.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_07.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_08.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_09.net'
	'/home/milton/Documentos/Github/valueIteration/triangletireworld_instances/triangle_tireworld_10.net'
	)

for i in "${arr[@]}"
do
	./main $i $1 >> $2
done
