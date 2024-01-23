#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char* argv[])
{
int fd = open(argv[1],O_WRONLY);
if(fd==-1) {perror("open"); return -1;}

struct flock fl;
fl.l_type =F_WRLCK;
fl.l_whence = SEEK_SET;
fl.l_start = 0;
fl.l_len = 6;

int f = fcntl(fd,F_SETLK,&fl);
if(f==-1) {perror("open"); return -1;}
printf("write lock success ... \n");
getchar();
close(fd);
return 0;
}
