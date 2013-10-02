#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main()
{
	char buf[1000];
	int fd;
	int i;
	fd=open("/dev/random",O_RDONLY);
	read(fd,buf,1000);
	for(i=0;i<1000;i++)
	printf("%d\n",buf[i]);
}
