#!/bin/bash

make all || exit;

echo ;
echo "Subject :"
valgrind ./subject.out 2>&1 | grep "lost\|no leaks are possible"

echo ;
echo "Rendu :"
valgrind ./rendu.out   2>&1 | grep "lost\|no leaks are possible"
