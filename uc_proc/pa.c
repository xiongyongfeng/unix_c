#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
  int fd = open(argv[1],O_WRONLY);
  if(fd==-1)
  {
    perror("open");
    return -1;
  }
  char* msg ="write into fifo...\n";
  write(fd,msg,strlen(msg));
  close(fd);
  return 0;
}
