#!/bin/bash

make || exit;

valgrind ./squad.out >result.log 2>valgrind.log

cat valgrind.log
diff subject.log result.log;
