
CC=g++
CFLAGS=-std=c++11 -Wall -g

findAllPerms: % : %.cpp FORCE
	$(CC) $(CFLAGS) $< -o $@ -lm

FORCE:
