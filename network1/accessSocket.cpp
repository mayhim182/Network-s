#include<iostream>
#include<vector>
#include<cstring>
#include<sys/socket.h>
#include<unistd.h>

int main()
{
	//Open a socket and perform necessary setup (not shown here)
	int sockfd = 1; //Your socket descriptor


	//Read the data from socket
	std::vector<char> buffer;
	char tempBuffer[4096]; //Temporary buffer to store each chunk of data

	ssize_t bytesRead;
	do{
		if(bytesRead>0) //Append the received data to the buffer
			bytesRead = recv(sockfd,tempBuffer,tempBuffer+bytesRead);
		else if(bytesRead<0)
			{
				perror("Error receiving data");
				close(sockfd);
				return 1;
			}
	}while(bytesRead>0)

	// Now 'buffer' contains the entire data received from the socket
	//Process or use the buffer as needed

	//Close the socket
	close(sockfd);


	return 0;
}