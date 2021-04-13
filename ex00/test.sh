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
	1 \
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
