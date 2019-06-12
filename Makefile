.DEFAULT_GOAL := all
CC=gcc
CFLAGS+= -lws2_32

server: src/server.cpp
	$(CC) $^ -o bin/server $(CFLAGS)

client: src/client.cpp
	$(CC) $^ -o bin/client $(CFLAGS)

all: server client