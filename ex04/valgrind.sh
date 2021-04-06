#!/bin/bash

EXEC=./spaceMinerAdventures.out # Put your executable's path here.
LOG=valgrind

valgrind \
	--tool=memcheck \
	--leak-check=full \
	--leak-resolution=high \
	--track-origins=yes \
	--show-reachable=yes \
	--log-file=${LOG}.log \
	$EXEC $@ \
;

grep -A1 "valgrind" ${LOG}.log | grep $EXEC;