#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
  int fd = open(argv[1],O_RDONLY);
  if(fd==-1)
  {
    perror("open");
    return -1;
  }
  char buf[128];
  int r = read(fd,buf,128);
  write(1,buf,r);
  close(fd);
  return 0;
}
