#!/usr/bin/env bash

for w in $(tr ' ' '\n' < words.txt | sort -u)
do
    echo "$w $(grep -cw "$w" <(tr ' ' '\n' < words.txt))"
done | sort -rnk2

