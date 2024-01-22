#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

  if(argc<2 || strcmp(argv[1],"--help")==0 )
  {
    printf("usage: ./a.out filename \n");
    return -1;

  }

  char* mesg = "hello\n";
  printf("%ld\n",strlen(mesg));
  int fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644);
  if(fd==-1)
  {
    perror("open");
    return -1;
  }
  
  int totalW=0;
  for(int i = 0;i<10;i++)
  {
    int w = write(fd,mesg,strlen(mesg));
    totalW+=w;
  }
  printf("共写入%d个字符\n",totalW);
  
  close(fd);
  return 0;
}
