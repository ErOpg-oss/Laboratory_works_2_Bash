#!/bin/bash

echo "Введите сообщение для отправки:"
read message
echo "$message" | nc localhost 12345
echo "Сообщение отправлено!"