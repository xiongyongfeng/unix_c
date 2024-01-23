#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
  //创建有名管道mkfifo
  int fd = mkfifo(argv[1],0644);
  if(fd==-1)
  {
    perror("mkfifo");
    return -1;
  }
  printf("create fifo success...\n");
  close(fd);
  return 0;
}
