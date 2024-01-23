#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(int argc, char* argv[])
{
  key_t key = ftok(argv[1],31);
  if(key==-1){perror("ftok");return -1;}
  printf("key:0x%x\n",key);

  int shmid=shmget(key,1024,IPC_CREAT|IPC_EXCL|0644);
  if(shmid==-1){perror("shmget");return -1;}
  printf("shmid:%d\n",shmid);
  return 0;
}
