#!/bin/sh
for i in `ls -d */`               
do
   git add $i
done
