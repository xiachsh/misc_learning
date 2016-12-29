.PHONY:all clean

all:server client

server:
	gcc -g -o server server.c -lpthread
client:
	gcc -g -o client client.c -lpthread

clean:
	rm -rf server client
