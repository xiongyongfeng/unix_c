#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int val = 0;
pthread_mutex_t mutex;
void* handle(void* arg)
{
  int tmp;
  for(int i =0;i<5000;i++)
  {
    pthread_mutex_lock(&mutex);
    tmp=val;
    tmp++;
    printf("tmp=%d\ttid:%lu\n",tmp,pthread_self());
    val = tmp;
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

int main(void)
{
  //初始化mutex锁
  pthread_mutex_init(&mutex,NULL);
  //创建两个线程
  pthread_t pid, tid;
  pthread_create(&tid,NULL,handle,NULL);
  pthread_create(&pid,NULL,handle,NULL);
  //等待线程的汇合
  pthread_join(tid,NULL);
  pthread_join(pid,NULL);

  pthread_mutex_destroy(&mutex);
  return 0;
}
