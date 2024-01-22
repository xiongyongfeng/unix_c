#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
void *doit(void *arg)
{
  printf("arg:%s\t\tpid:%d\ttid:%lu\n", (char *)arg, getpid(), pthread_self());
}

int main(void)
{
  // 创建一个新的线程
  pthread_t tid;
  if (pthread_create(&tid, NULL, doit, "new") != 0)
  {
    perror("pthread");
    return -1;
  }
  // 目前是两个线程,这两个线程是异步的?
  sleep(1);
  doit("main");
  return 0;
}
