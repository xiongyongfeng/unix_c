#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>


int main(int argc, char* argv[])
{
  key_t key = ftok(argv[1],31);
  if(key==-1){perror("ftok");return -1;}
  printf("key:0x%x\n",key);

  int shmid=shmget(key,1024,IPC_CREAT|0644);
  if(shmid==-1){perror("shmget");return -1;}
  printf("shmid:%d\n",shmid);
  //使用共享内存段的id,将共享内存段关联到进程的地址空间
  void* p = shmat(shmid,NULL,0);
  if(p==(void*)-1){perror("shmat error");return -1;}
  printf("%s\n",(char*)p);

  return 0;
}
