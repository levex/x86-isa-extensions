#!/bin/bash

EXTENSIONS="mmx sse"

for i in ${EXTENSIONS}
do
	${i}/${i}_test
done
