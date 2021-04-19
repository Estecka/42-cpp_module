#!/bin/bash

make subject.out || exit;

./subject.out > result.log;
diff subject.log resylt.log;
