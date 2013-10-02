#include<stdio.h>
#include<sys/inotify.h>
#define BUF_LEN 1000

int main()
{
	int fd,wd;
	fd=inotify_init();
	printf("%d\n",fd);
	wd=inotify_add_watch(fd,"/tmp",IN_ACCESS|IN_MODIFY|IN_CREATE);
	printf("%d\n",wd);
	char buf[BUF_LEN] __attribute__((aligned(4)));
	ssize_t len,i=0;
while(1){
	len=read(fd,buf,BUF_LEN);
	printf("%d\n",len);
	i=0;
	while(i<len){
		struct inotify_event *event=(struct inotify_event *)&buf[i];
		printf("wd=%d mask=%d cookie=%d len=%d dir=%s\n",event->wd,event->mask,event->cookie,event->len,(event->mask&IN_ISDIR)?"yes":"no");
		if(event->len)
			printf("name=%s\n",event->name);
		i+=sizeof(struct inotify_event)+event->len;
	}
}
	close(fd);
	return 0;
}
