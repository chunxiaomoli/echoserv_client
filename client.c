#include "unp.h"

int main(int argc,char* argv[])
{
    int sockfd[5];
    struct sockaddr_in servaddr;
	int i;
    if(argc!=2)
    {
        printf("usage:client <server IP>\n");
        return 0;
    }
	for( i=0;i<5;i++)
    {
		sockfd[i]=socket(AF_INET,SOCK_STREAM,0);
    	bzero(&servaddr,sizeof(servaddr));
    	servaddr.sin_family=AF_INET;
    	servaddr.sin_port=htons(PORT);
    	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
    	connect(sockfd[i],(struct sockaddr*)&servaddr,sizeof(servaddr));
	}
    str_echo_client(stdin,sockfd[i]);
    return 0;
}
