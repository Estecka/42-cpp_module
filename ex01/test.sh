#!/bin/bash

make || exit;
./fixed.out >result.log;
diff subject.log result.log
