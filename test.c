#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void send_UART(char* port, char* data){
	strcat(data, "\r\n");
	int fd = open (port, O_WRONLY);
	if (fd == -1){
		perror("Error during serial port opening");
	}
	size_t lenght = strlen(data);
	if (write(fd, data, lenght) == -1){
		perror("Error during serial port writting");
		close(fd);
		exit(1);
	}
}

int main(int argc, char *argv[]){
	char *port = argv[1];
	char *data = argv[2];
	if (argc == 3){
		send_UART(port, data);
	}
	return 1;
}
