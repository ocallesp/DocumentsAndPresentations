/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			bypass_aslr_dep.c	
=============================================================================*/

/* Compile: gcc -fno-stack-protector bypass_aslr_dep.c -o bypass_aslr_dep          */
/* Enable ASLR: echo 2 > /proc/sys/kernel/randomize_va_space */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

int start_server(void)
{
	int socket_desc, client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_message[150];

	//Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 2222 );

	//Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 1);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");

    //Receive a message from client
	close(socket_desc);
	dup2(client_sock, 0);
	dup2(client_sock, 1);
	dup2(client_sock, 2);
	return 0;
}


void helper() {
    asm("pop %rdi; pop %rsi; pop %rdx; ret");
}

int vuln() {
    char buf[150];
    ssize_t b;
    memset(buf, 0, 150);
    printf("Enter input: ");
    b = read(0, buf, 400);

    printf("Recv: ");
    write(1, buf, b);
    return 0;
}

int main(int argc, char *argv[]){
    setbuf(stdout, 0);
	if(start_server() == 1)
		return 1;

	vuln();
    return 0;
}
