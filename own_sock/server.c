#include <stdio.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argv, char *argc[])
{
	int socketfd, new_socket;
	struct sockaddr_in address, con_addr;
	int con_len = sizeof con_addr;
	char prt_addr[35];
	int opt = 1;
	int recvlen;
	char recv_buf[1024];
	char *hello = "Hello from server";

	if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof opt)) {
		perror("setsocket");
		exit(EXIT_FAILURE);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	if (bind(socketfd, (struct sockaddr *)&address, sizeof (address))) {
		perror("bind error");
		exit(EXIT_FAILURE);
	}

	if (listen(socketfd, 3) < 0) {
		perror("listen error");
		exit(EXIT_FAILURE);
	}
	
	while(recv_buf[0] != 'q') {
		if ((new_socket = accept(socketfd, NULL, NULL)) < 0) {
			perror("accept error");
			exit(EXIT_FAILURE);
		}

		recvlen = read(new_socket, recv_buf, 1024);
		
		//inet_ntop(AF_INET, con_addr.sin_addr, prt_addr, sizeof prt_addr);
		//printf("recv from %s\n", prt_addr);
		
		printf("%s\n", recv_buf); 
		send(new_socket, hello, strlen(hello), 0);
	}
	return 0;
}	
