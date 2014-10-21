#include "unp.h"

void str_echo(int connfd)
{
    ssize_t n;
    char buf[BUFSIZE];

    again:
        while( (n=readline(connfd,buf,BUFSIZE))>0)
        {
            writen(connfd,buf,n);
			printf("subprocess pid=%d\n",getpid());
        }
        if(n<0&&errno==EINTR)
            goto again;
        else if(n<0)
            printf("str_echo:read error\n");
}
