#include<stdio.h>
#include<signal.h>

int main()
{
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set,2);
  sigaddset(&set,3);

  int is = sigismember(&set,3);
  if(is==-1)
  {
    perror("sigismember");
    return -1;
  }
  if(is)
  {
    printf("signum 3 is member of set....\n");
  }
  else
  {
    printf("signum 3 is not a member of set....\n");
  }

  sigdelset(&set,3);
  is=sigismember(&set,3);
  if(is)
  {
    printf("signum 3 is member of set....\n");
  }
  else
  {
    printf("signum 3 is not a member of set....\n");
  }


  return 0;
}
