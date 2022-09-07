#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 12000

void print_usage(char * cmd)
{
        fprintf(stderr," %s usage:\n",cmd);
        fprintf(stderr,"%s IP_Addr [port]\n",cmd);

}

int main(int argc,char** argv)
{
        struct sockaddr_in server;
        int ret;
        int send_len;
        int recv_len;
        int port;
        int sockfd;
        int sendnum;
        int recvnum;
        char send_buf[2048];
        char recv_buf[2048];
	//初始化，分配空间
        memset(send_buf,0,2048);
        memset(recv_buf,0,2048);
    //     if ((2>argc)|| (argc >3))
    //     {
    //             print_usage(argv[0]);
    //             exit(1);

    //     }

    //    if (3==argc)
    //    {
    //    }

        if (-1==(sockfd=socket(AF_INET,SOCK_DGRAM,0)))
        {
                perror("can not create socket\n");
                exit(1);
        }

        memset(&server,0,sizeof(struct sockaddr_in));
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("192.168.233.129");//argv[1]
        server.sin_port = htons(12000);

    int addr_len = sizeof(server);
    while(1){
    printf("ucp>");
	//gets(send_buf);
	fgets(send_buf,2048,stdin);
    if (0==strcmp(send_buf,"quit"))
    {
		perror("the client break the server process\n");
		close(sockfd);
		break;
	}
    #ifdef DEBUG
		printf("%s\n",send_buf);
  	#endif 
// sendto (SOCKET s,void *buf,int len,unsigned int flags, struct sockaddr *from,int fromlen)
	if (0>(send_len=sendto(sockfd,send_buf,strlen(send_buf),0,(struct sockaddr *)&server, addr_len)))
	{
		perror("send data error\n");
		close(sockfd);
		exit(1);

	}
//      recvfrom (SOCKET s,void *buf,int len,unsigned int flags, struct sockaddr *from,int *fromlen)
	if (0>(recv_len=recvfrom(sockfd,recv_buf,2048,0,(struct sockaddr *)&server, &addr_len)))
	{
		perror("recv data error\n");
		close(sockfd);
		exit(1);
	}
	
	recv_buf[recv_len]='\0';

	printf("the message from the server is:%s\n",recv_buf);
    }
	close(sockfd);

}	
