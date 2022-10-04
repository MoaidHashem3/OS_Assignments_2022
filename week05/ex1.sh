#!/bin/bash
gcc -o publisher publisher.c
gcc -o subscriber subscriber.c

 gnome-terminal -- ./publisher

for ((i=0; i<4; i++))
do
 gnome-terminal -- ./subscriber
done
