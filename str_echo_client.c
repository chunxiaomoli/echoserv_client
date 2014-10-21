#include "unp.h"

void str_echo_client(FILE* fp,int sockfd)
{
    char sendbuf[BUFSIZE],recvbuf[BUFSIZE];
    while(fgets(sendbuf,BUFSIZE,fp)!=NULL)
    {
        if(writen(sockfd,sendbuf,strlen(sendbuf))<0)
        {
            printf("write error\n");
            exit(0);
        }
        if(readline(sockfd,recvbuf,BUFSIZE)==0)
        {
            printf("server terminated\n");
            exit(0);
        }
        fputs(recvbuf,stdout);
    }
}
