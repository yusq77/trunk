#!/bin/bash

for (( i=0;i<10;i++ ))
do
    m=$[$i+1]
     sed -i "s/Test$m/FindInPartiallySortedMatrix$m/g" 04_FindInPartiallySortedMatrix.cpp
     #sed -i "s/Test$m/replaceSpaces$m/g" 05_ReplaceSpaces.cpp
done
