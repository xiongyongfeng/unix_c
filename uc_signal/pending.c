#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(void)
{


  sigset_t set,oldset,pendingset;
  sigemptyset(&set);
  sigemptyset(&oldset);
  sigemptyset(&pendingset);
  sigaddset(&set,2);
  sigaddset(&set,3);
  sigaddset(&set,9);

  if(sigprocmask(SIG_BLOCK,&set,&oldset)==-1)
  {
   perror("sigprocmask");
   return -1;
  }
  int step = 0;
  while(step < 10){
    sleep(1);
    sigpending(&pendingset);
    int is = sigismember(&pendingset,2);
    if(is==-1){perror("sigismember");return -1;}
    is?printf("yes\n"):printf("no\n");
    step++;
  }

  if(sigprocmask(SIG_SETMASK,&oldset,NULL)==-1)
  {
   perror("sigprocmask");
   return -1;
  }

  return 0;
}
