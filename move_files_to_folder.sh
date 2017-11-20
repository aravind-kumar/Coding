#!/bin/sh

for i in `ls -l | awk {'print $9'} | cut -f 1 -d .`
do
    mkdir $i
    ext=".cpp"
    filename="$i$ext"
    mv $filename $i
done
