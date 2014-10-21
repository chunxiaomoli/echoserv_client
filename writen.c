#include "unp.h"

ssize_t writen(int fd,const void* vptr,size_t n)
{
	size_t nleft,nwritten;
	const char *ptr;
	ptr=vptr;
	nleft=n;
	while(nleft>0)
	{
		if( (nwritten=write(fd,ptr,nleft))<=0)
			return nwritten;
		nleft-=nwritten;
		ptr+=nwritten;
	}
	return n;
}
