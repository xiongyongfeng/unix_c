#include<stdio.h>
#include<string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  int s_fd = socket(AF_INET,SOCK_STREAM,0);

  //服务器初始化
  struct sockaddr_in serv;
  serv.sin_family = AF_INET;
  serv.sin_port = htons(5566);
  inet_pton(AF_INET,argv[1],&serv.sin_addr);

  //连接服务器
  int c = connect(s_fd,(struct sockaddr*)&serv, sizeof(serv));
  if(c==-1){perror("connect");return -1;}

  char *msg = "this is a test...\n";
  write(s_fd,msg,strlen(msg));

  char buf[128];
  int r = read(s_fd,buf,128);
  write(1,buf,r);
  close(s_fd);
  return 0;
}
