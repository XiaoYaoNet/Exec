#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc,char *argv[])
{
    int fd1;
    int fcnret=0;
    char argbuf[24];
    fd1=open("./text1.txt",O_RDWR|O_CREAT);
    
    fcnret=fcntl(fd1,F_SETFD,0);

    fcnret=fcntl(fd1,F_GETFD);
    printf("now the file descriptor flag value=%d\n",fcnret);

    write(fd1,"now it is written before execl\n",strlen("now it is written before execl"));

    sprintf(argbuf,"%d",fd1);
    printf("argbuf=%s\n",argbuf);


    execl("./example1",argbuf,NULL);

    printf("after execl\n");
    if(write(fd1,"written after execl\n",strlen("written after execl\n"))>0)
    {
         printf("write after execl ok");
    }else{
         printf("write after execl fail");
    }
    return 0;
}
