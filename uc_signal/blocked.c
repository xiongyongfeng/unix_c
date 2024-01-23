#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(void)
{


  sigset_t set,oldset;
  sigemptyset(&set);
  sigaddset(&set,2);
  sigaddset(&set,3);
  sigaddset(&set,9);

  if(sigprocmask(SIG_SETMASK,&set,&oldset)==-1)
  {
   perror("sigprocmask");
   return -1;
  }
  printf("sleep 10s...\n");
  sleep(10);
  printf("after sleep 10s...\n");

  if(sigprocmask(SIG_SETMASK,&oldset,NULL)==-1)
  {
   perror("sigprocmask");
   return -1;
  }

  return 0;
}
