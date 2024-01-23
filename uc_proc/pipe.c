#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
#include<sys/wait.h>
int main(void){
  //创建无名管道pipe(fd)
  int fd[2];
  if(pipe(fd)==-1){ perror("pipe"); return -1;}

  //创建子进程
  pid_t child = fork();
  if(child==-1){ perror("pipe"); return -1;}
  if(child==0){//子进程
          close(fd[1]);
          char buf[128];
          int r = read(fd[0],buf,128);
          write(1,buf,r);
          close(fd[0]);
          exit(0);

  }
  else
  {
    close(fd[0]);
    char* msg = "this is a test...\n";
    write(fd[1],msg,strlen(msg));
    wait(NULL);
    close(fd[1]);
  }
  return 0;

}
