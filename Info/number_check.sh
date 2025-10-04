#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Ошибка: Необходимо передать число"
    exit 1
fi

if [ $(($1 % 2)) -eq 0 ]; then
    echo "Число $1 четное"
else
    echo "Число $1 нечетное"
fi