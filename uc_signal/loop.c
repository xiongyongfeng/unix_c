#include<stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

//自定义信号处理函数
void handle(int n)
{
  printf("recv...%d\n",n);
  return;
}

int main(void)
{
  signal(2,SIG_IGN);//忽略2号信号,
  //signal(3,SIG_IGN);//忽略2号信号,
  signal(3,handle);//忽略2号信号,
  signal(9,SIG_IGN);//忽略2号信号,
  //默认从父进程(bash)中继承信号处理函数
  int pid = fork();
  if(pid==-1)
  {
    perror("fork");
    return -1;
  }
  while(1);
  return 0;
}
