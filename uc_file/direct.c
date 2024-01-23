#include<stdio.h>
#include<t_file.h>
#include<string.h>

int main(int argc, char* argv[]){
  //0 1 2
  char* msg = "this is a test ...\n";
  int flags = O_WRONLY | O_CREAT | O_TRUNC;
  int fd = open(argv[1],flags,0644); //fd=3
  if(fd==-1){
  perror("open error");
  return -1;
  }

  int s_fd =dup(1); // s_fd = 4
  //printf("s_fd=%d\n",s_fd);
  dup2(fd,1);
  close(fd);

  //printf("%shihi\n",msg);
  write(1,msg,strlen(msg));

  dup2(s_fd,1);
  close(s_fd);
  write(1,msg,strlen(msg));

  return 0;
}
