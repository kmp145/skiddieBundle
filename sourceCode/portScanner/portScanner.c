#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h> 
#include "io.h"

int createSocket(int port){
	 
	int sockfd;

	struct sockaddr_in serverAddress;
	
	memset(&serverAddress, 0, sizeof(serverAddress));//intialise serv_addr to 0
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(port);//set port number

	sockfd = socket(AF_INET, SOCK_STREAM, 0);//create socket
	bind(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
	fprintf(stdout,"Socket successfully created on port %d\n", port);
	return sockfd;
}

int testPort(int port, char targetIP[17]){

	int sockfd;
	sockfd = createSocket(port);
	struct sockaddr_in targetAddress;
	memset(&targetAddress,0,sizeof(targetAddress));
	targetAddress.sin_family = AF_INET;
	targetAddress.sin_addr.s_addr = inet_addr(targetIP);
	targetAddress.sin_port = htons(targetPort);
}

int main(int argc, char *argv[]){

	/*
	Usage for args:
		argv[0] : is file executed (./portScanner)
		argv[1] : is targetIP
		argv[2] : number of threads
		argv[3] : is starting port
		argv[4] : is ending port
	*/
	
	fprintf(stdout, "%s\n", argv[0]);//DEBUG
	fprintf(stdout, "%s\n", argv[1]);//DEBUG
	fprintf(stdout, "%d\n", argc);
	
	/*variable declaration*/
	int startPort, endPort, threadCount;
	char *targetIP;
	targetIP = malloc(sizeof(char)*17);
	
	if (argc == 1){//No line arguements given
		fprintf(stdout, "No arguements were given from the command line\n\n");//DEBUG
		
		inputStr(targetIP, "Enter target IP:\t", sizeof(char)*17, 1);
		fprintf(stdout, "\n%s\n", targetIP);//DEBUG
		/*
		IF (!VALID IP)
			DO SOMETHING
		*/
		
		threadCount = inputInt(&threadCount,"Enter number of threads you wish to use (Higher the better):\t",sizeof(threadCount),1);
		
		if(threadCount > 0)
			fprintf(stdout, "%d\n", threadCount);//DEBUG
		else
			exit(2);//QUIT HERE
			
		startPort = inputInt(&startPort, "Enter the starting port:\t", sizeof(startPort), 1);
		if(startPort > 0)
			fprintf(stdout, "%d\n", startPort);//DEBUG
		else
			exit(3);//QUIT HERE
			
		endPort = inputInt(&endPort, "Enter the starting port:\t", sizeof(endPort), 1);
		if(endPort > 0 && endPort > startPort)
			fprintf(stdout, "%d\n", endPort);//DEBUG
		else
			exit(3);//QUIT HERE
	}
	
	else if(argc > 2){//flesh ouut this part
		
		//validateIP()
		if (argc > 3){
			//validate thread count
			if (argc > 4){
				//validate startPort
				if (argc > 5){
					//validate endPort
					//ignore rest of arguements
				}
			}
			
		}
		
	}
	
	
	return 0;
}
