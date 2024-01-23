#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include "t_main.h"
int main(void)
{
  //创建套接字
  int s_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(s_fd == -1){perror("socket");return -1;}

  struct sockaddr_in serv; // 采用ipv4地址家族的结构体
  serv.sin_family = AF_INET;//初始化ipv4地址
  serv.sin_port = htons(5566);
  serv.sin_addr.s_addr = htonl(INADDR_ANY);

  //将套接字设备与本地ip和端口号绑定
  int b =  bind(s_fd, (const struct sockaddr*)&serv,sizeof(serv) );
  if(b == -1){perror("bind");return -1;}
  //监听
  listen(s_fd,5);

  //从未决队列中提取,建立连接
  while(1)
  {
    int c_fd = accept(s_fd, NULL,NULL);
    if(c_fd == -1){perror("accept");return -1;}
    //读取内容                                                                                                  t_main(c_fd);
    close(c_fd);
  }


  return 0;
}
