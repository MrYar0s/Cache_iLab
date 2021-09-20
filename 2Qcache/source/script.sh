#!/bin/bash
responce=$(./main)
for var in $(cat ../test/test1.dat)
do
	$var
done