#!/bin/zsh

TESTS=(
	'FILE=Makefile	FIND=clean	REPLACE=dirty'
	'FILE=Makefile	FIND=all  	REPLACE=none'
	'FILE=main.cpp	FIND=include 	REPLACE=exlude'
	'FILE=main.cpp	FIND=void	REPLACE=whole'
	'FILE=main.cpp	FIND=beep	REPLACE=boop'
	'FILE=StreamCrawler.cpp	FIND=Crawler	REPLACE=Swimmer'
	'FILE=StreamCrawler.hpp	FIND="some characters"	REPLACE="many entities"'
	'FILE=test.sh	FIND=FILE	REPLACE=FOLDER'
);

make || exit;

for t in $TESTS;
do;
	eval $t;
	echo $t;
	./replace $FILE $FIND $REPLACE;
	sed "s/$FIND/$REPLACE/g"	<$FILE	>"$FILE.sed";
	diff "$FILE.replace" "$FILE.sed" || exit;
done;

