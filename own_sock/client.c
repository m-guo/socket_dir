#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main()
{
	int socketfd;
	struct sockaddr_in ser_addr;
	char *hello = "Hello frome client";
	char recv_buf[1024];
	int recv_len = 0;

	if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket error");
		exit(EXIT_FAILURE);
	}
	
	memset(&ser_addr, 0, sizeof ser_addr);
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, "127.0.0.1", &ser_addr.sin_addr) <= 0) {
		perror("Invailed addrss");
		exit(EXIT_FAILURE);
	}
	
	if (connect(socketfd, (struct sockaddr *) &ser_addr, sizeof(ser_addr)) < 0) {
		perror("connect failed");
		exit(EXIT_FAILURE);
	}
	
	send(socketfd, hello, strlen(hello), 0);
	
	recv_len = read(socketfd, recv_buf, 1024);
	printf("%s\n", recv_buf);
	
	return 0;
}
