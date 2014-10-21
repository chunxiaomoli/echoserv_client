#ifndef UNP_H_INCLUDED
#define UNP_H_INCLUDED

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

#define PORT 3135
#define BUFSIZE 4096
#define LISTENQ 1024
void sig_chld(int signo);
extern ssize_t readline(int fd,void *vptr,size_t maxline);
extern ssize_t writen(int fd,const void* vptr,size_t n);
extern void str_echo(int sockfd);
extern void str_echo_client(FILE* fp,int sockfd);
#endif // UNP_H_INCLUDED
