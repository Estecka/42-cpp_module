#!/bin/bash

make || exit;

valgrind \
	--tool=memcheck \
	--leak-check=full \
	--leak-resolution=high \
	--track-origins=yes \
	--show-reachable=yes \
	--log-file=valgrind.log \
	./bocalFantasy.out >result.log

cat valgrind.log
diff subject.log result.log;
