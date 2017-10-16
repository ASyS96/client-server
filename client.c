/*
 * Auth: ASyS
 *
 * File: client.c
 *
 * Desc: Rudimentary client program that takes SERVER_IP_ADDRESS and
 *       SERVER_PORT_NUMBER as argument and attempt to connect to them.
 *       Upon successful connection, it reads the first 100 characters sent
 *       to it and puts it to the STDOUT.
 *
 * Err : Error handling is minimal or non-existent for most part except 
 *       when socket creation failed or connection to server failed in which
 *       error message will be displayed in addition to non-zero return
 *       value. SERVER_IP_ADDRESS and SERVER_PORT_ADDRESS validity is not
 *       verified. Therefore, wrong formatting behavior is not known...
 *       (At least to the author ;-).
 */
#include <stdlib.h>//atoi() ascii to integer
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>//htons()
#include <netinet/in.h>//struct sockaddr_in

int main(int argc, char **argv)
{
    int sockd;//Socket descriptor for this client

    if((sockd = socket(AF_INET, SOCK_STREAM, 0)) ==1) {
	fprintf(stderr, "Socket creation failed\n");
	return 1;
    }
    struct sockaddr_in svr;//Struct used to store target server address
    svr.sin_addr.s_addr = inet_addr(argv[1]);//Destination server IP add.
					     //+assigned from cmdline arg.
    svr.sin_family = AF_INET;
    svr.sin_port = htons(atoi(argv[2]));//Destination port
    
    printf("Connecting to %s:%s\n", argv[1], argv[2]);
    if(connect(sockd, (struct sockaddr *)&svr, sizeof svr) < 0){
	fprintf(stderr, "Connection error\n");
	return 2;
    }
    char msg[100];
    if(recv(sockd, msg, sizeof msg, 0) < 0)
	fprintf(stderr, "Retrieval failed\n");
    else
	printf(msg);
}
