#!/bin/bash

make || exit;

./convert \
	"'a'" \
	"' '" \
	"'\\\'" \
	"'\''" \
	"'abc'" \
	"'\'" \
	"'''" \
	\
	92 \
	-12 \
	-2147483648 \
	10000000000f \
	1.3 \
	1.0.2 \
	1.3f \
	nan \
	nanf \
	+inf \
	-inf \
	+inff \
	-inff \
;
