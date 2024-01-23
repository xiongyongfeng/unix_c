#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(){
  char *p;
  printf("pid=%d\n",getpid());
  p =(char*) malloc(1024);
  printf("&p=%p\n",&p);
  printf("p=%p\n",p);

  strcpy(p,"hello beijing");
  printf("before free p: %s\n",p);
  free(p);
  p=NULL;
  printf("after free p: %s\n",p);
  printf("&p=%p\n",&p);
  printf("p=%p\n",p);
  getchar();
  return 0;
}
