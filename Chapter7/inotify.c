#include<stdio.h>
#include<inotify.h>

int main()
{
	int fd,wd;
	fd=inotify_init();
	wd=inotify_add(fd,"./",IN_CREATE);
	
	char buf[BUF_LEN] __attribute__((aligned(4)));
	ssize_t len,i=0;

	len=read(fd,buf,BUF_LEN);

	while(i<len){
		struct inotify_event *event=(struct inotify_event *)&buf[i];
		printf("wd=%d mask=%d cookie=%d len=%d dir=%s\n",event->wd,event->mask,event->cookie,event->len,(event->mask&IN_ISDIR)?"yes":"no");
		if(event->len)
			printf("name=%s\n",event->name);
		i+=sizeof(struct inotify_event)+event->len;
	}
	close(fd);
	return 0;
}
