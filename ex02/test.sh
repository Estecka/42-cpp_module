#!/bin/bash

make || exit;
./globalbankster.out > out.log || exit;
diff out.log 19920104_091532.log;
