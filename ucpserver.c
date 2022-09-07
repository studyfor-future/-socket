/**********************************************************\
*                                                         *\
*  program name:tcpserver.c                               *
*  Author:Liang gang & Hu Xiao-qin                        *\
*  Funtion:This program is just a demostrate program      *\
*          to tell students how to use socket to          *\
*          make a tcp communation.                        *\
*  Date: 03-06-2009                                       *\
*                                                         *\
***********************************************************/


#include<stdlib.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 12000

int main(int argc,char** argv)
{
	struct sockaddr_in server;
	struct sockaddr_in client;
	int len;
	int port;
	int sockfd;
	int sendnum;
	int opt;
	int recvnum;
	char send_buf[2048];
	char recv_buf[2048];

      //if (2==argc)

	port= PORT;
	memset(send_buf,0,2048);
	memset(recv_buf,0,2048);
	
    //   opt = SO_REUSEADDR;
      

      if (-1==(sockfd=socket(AF_INET,SOCK_DGRAM,0)))
      {
	 perror("create listen socket error\n");
	 exit(1);
      }
    //   setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	printf("created socket, server_fd: %d\n", sockfd);
      #ifdef DEBUG
		printf("the sockfd id is %d\n",sockfd);
      #endif

     memset(&server,0,sizeof(struct sockaddr_in));
     server.sin_family = AF_INET;
     server.sin_addr.s_addr = htonl(INADDR_ANY);
     server.sin_port = htons(port);

     if (-1==bind(sockfd,(struct sockaddr *)&server,sizeof(struct sockaddr)))
     {
	perror("bind error\n");
	exit(1);

     }
	// printf("bind complete, port number:%d\n", ntohs(server.sin_port));
	printf("waiting for data ......\n");
	int addr_len = sizeof(client);
    while (1)
    {
    
	// sendnum = sprintf(send_buf,"hello,the guest from %s\n",inet_ntoa(client.sin_addr));
    if (0>(recvnum = recvfrom(sockfd,recv_buf,sizeof(recv_buf),0,(struct sockaddr *)&client, &addr_len)))
	{
		perror("recv error\n");
		continue;
	}
	recv_buf[recvnum]='\0';
	printf ("the message from the client is: %s\n",recv_buf);
	memcpy(send_buf,recv_buf,recvnum);
	sendnum = recvnum;
  	if(0>(sendto(sockfd,recv_buf,sendnum,0,(struct sockaddr *)&client, addr_len))){
		perror("sendto error\n");
		continue;
	}


   }


    close(sockfd);
    return 0;



}




