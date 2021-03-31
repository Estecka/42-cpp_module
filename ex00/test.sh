#!/bin/bash

make || exit;

./sorcerer.out > result.log;
diff subject.log result.log;
