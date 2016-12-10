#!/bin/bash

output=$(cat /dev/stdin | grep -oE '^.*:[0-9]+:([0-9]+:)?[[:blank:]](fatal[[:blank:]])?error:[[:blank:]](.+)$' \
| grep -vE '^.*\(Each[[:blank:]]undeclared[[:blank:]]identifier[[:blank:]]is[[:blank:]]reported[[:blank:]]only[[:blank:]]once$' \
| grep -vE '^.*for[[:blank:]]each[[:blank:]]function[[:blank:]]it[[:blank:]]appears[[:blank:]]in.\)$' \
| sed -n '$=');

echo $output