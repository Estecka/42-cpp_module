#!/bin/bash

make all || exit;

./claptrap.out > claptrap.log
./fragtrap.out > fragtrap.log
./scavtrap.out > scavtrap.log
