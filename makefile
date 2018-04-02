all: socket_server socket_client

socket_server: socket_server.c
	gcc -o socket_server socket_server.c

socket_client: socket_client.c
	gcc -o socket_client socket_client.c
clean:
	rm socket_server socket_client
