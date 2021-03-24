#!/bin/bash

make || exit;
./fixed.out >rendu.log;
diff subject.log rendu.log
