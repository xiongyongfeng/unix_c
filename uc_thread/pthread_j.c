#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* handler(void *arg){
  printf("handler running...\n");
  sleep(3);
  return (void*)1;
}
void* handler1(void *arg){
  printf("handler1 running...\n");
  sleep(3);
  //终止当前线程
  pthread_exit((void*)3);
}

void* handler2(void* arg)
{
  while(1){
    printf("handler2 running...\n");
    sleep(1);
  }
  return NULL;
}

int main(){
  //创建一个新的线程
  pthread_t tid;
  pthread_create(&tid,NULL,handler,NULL);
  //汇合线程
  void* retval;//退出状态吗
  pthread_join(tid,&retval);
  printf("handler exit code...%d\n",(int)(intptr_t)retval);

  pthread_create(&tid,NULL,handler1,NULL);
  pthread_join(tid,&retval);
  printf("handler1 exit code...%d\n",(int)(intptr_t)retval);

  pthread_create(&tid,NULL,handler2,NULL);
  sleep(4);
  //给线程发送取消请求
  pthread_cancel(tid);
  pthread_join(tid,&retval);
  if(retval==PTHREAD_CANCELED)
  printf("handler2 exit code...%d\n",(int)(intptr_t)retval);
  return 0;
}
