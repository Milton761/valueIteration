#!/bin/bash


declare -a arr=(
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation01.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation02.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation03.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation04.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation05.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation06.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation07.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation08.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation09.net'
	'/home/milton/Documentos/Github/valueIteration/navigation_instances/navigation10.net'

	)

for i in "${arr[@]}"
do
	./main $i $1 >> $2
done
