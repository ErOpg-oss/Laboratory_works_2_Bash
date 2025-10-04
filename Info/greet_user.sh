#!/bin/bash
read name 
if [ $# -eq 0 ]; then
    echo "Пожалуйста, укажите ваше имя"
else
    echo "Привет, $1!"
fi