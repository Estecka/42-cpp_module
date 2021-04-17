#!/bin/bash

make || exit;

./templates.out > result.log;
diff subject.log result.log;
