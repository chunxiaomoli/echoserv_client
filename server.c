#include "unp.h"

int main(void)
{
	int sockfd,connfd;
	pid_t chldpid;
	socklen_t chldlen;
	
	struct sockaddr_in servaddr,cliaddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(PORT);
	bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	listen(sockfd,LISTENQ);
	signal(SIGCHLD,sig_chld);
	for(;;)
	{
		chldlen=sizeof(cliaddr);
		if( (connfd=accept(sockfd,(struct sockaddr*)&cliaddr,&chldlen))<0 )
		{
			if(errno==EINTR)
			{
				printf("interupted sys call\n");
				continue;// restart sys call by self;
			}
		}	
		if( (chldpid=fork())==0)
		{
			close(sockfd);
			str_echo(connfd);
			exit(0);
		}
		close(connfd);
	}
}
