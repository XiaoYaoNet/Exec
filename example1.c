#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc,char *argv[])
{
    int tmp_fd=-1;
    char buf[48];
    memset(buf,0,48);
    
    printf("now in example1\n");

    if(argv[0]!=NULL)
    {
        printf("argv[0]=%s\n",argv[0]);
        tmp_fd=atoi(argv[0]);
    }
   
    if(tmp_fd>0)
    {
        lseek(tmp_fd,0,SEEK_SET);
        if(read(tmp_fd,buf,48)>=0)
        {
            printf("now in example1,buf is:%s\n",buf);
        }else{
            printf("error is:%s\n",strerror(errno));
        }
    }
    return 0;
}
