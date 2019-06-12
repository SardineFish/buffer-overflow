# Buffer Overflow Attack Demo

A demo to perform a buffer overflow attack.

## Require
- Windows NT
- GCC
- An Virtual Machine

## Build & Run
Directly build with `make`
```shell
$ make
```
Run the Server
```shell
$ ./bin/server
```

Run the Client
```shell
$ ./bin/client
```

**Notice**

The server will setup an UDP server on port `3000`, and the client will connect to the server. The port can be edited in `server.cpp`.

## Usage
Write the code in `client.cpp` to perform a buffer overflow attack on the server.

**Please be careful to do these on your physical machine.**

Good luck :)