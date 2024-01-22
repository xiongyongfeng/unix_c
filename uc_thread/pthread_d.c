#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* doit(void* arg)
{
  for(int i =0;i<5;i++){
    printf("thread:%s\tpid:%d\ttid:%lu\n",(char*)arg,getpid(),pthread_self());
    usleep(5000000);
  }
  return NULL;
}
int main(void){
  //创建一个新的线程
  pthread_t tid;
  pthread_create(&tid,NULL,doit,"new");
  //分离新线程
  pthread_detach(tid);
  for(int i =0;i<5;i++){
    printf("thread:%s\tpid:%d\ttid:%lu\n","main",getpid(),pthread_self());
    usleep(10000000);
  }
  return 0;
}
