#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
//单向链表的结构体
typedef struct node{
  int data;
  struct node* next;
}node_t;
typedef node_t* list_t;

//定义链表
list_t head=NULL;

//定义锁的全局变量
pthread_mutex_t mutex;

//定义条件变量
pthread_cond_t cond;

//生产者线程
void* product(void* arg){

  node_t* new;
  while(1){//不断生成
    //生产一个新节点
    new=(node_t *)malloc(sizeof(node_t));
    new->data = rand()%1000+1;
    printf("p:%d\n",new->data);
    //将新节点插入链表的头部
    //加锁
    pthread_mutex_lock(&mutex);
    new->next = head;
    head=new;
    //解锁
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);//告知线程,cond为真
    sleep(rand()%3+1);
  }
  return NULL;
}

//消费者线程
void* consumer(void* arg){
  node_t* tmp;
  while(1){//不断消
    pthread_mutex_lock(&mutex);
    while(head==NULL){
      //阻塞等待链表不为空
      pthread_cond_wait(&cond,&mutex);//解锁等待,原子操作
    }
    tmp = head;
    head = head->next;
    pthread_mutex_unlock(&mutex);
    printf("c:%d\n",tmp->data);
    free(tmp);
    tmp=NULL;
    sleep(rand()%3+1);
  }
  return NULL;
}

int main(void){
  srand(time(NULL));
  pthread_mutex_init(&mutex,NULL);
  pthread_cond_init(&cond,NULL);
  //创建两个线程,生产者消费者
  pthread_t pid,cid;
  pthread_create(&pid,NULL,product,NULL);
  pthread_create(&cid,NULL,consumer,NULL);
  //等待线程的汇合
  pthread_join(pid,NULL);
  pthread_join(cid,NULL);
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  return 0;
}
