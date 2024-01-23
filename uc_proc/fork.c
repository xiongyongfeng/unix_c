#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<error.h>
int main(void){
  pid_t pid;
  pid = fork();
  if(pid==-1) {perror("fork"); return -1; }
  if(pid==0){
     printf("child process...\n");

  }
  else{
     printf("parent process...\n");


  }
  printf("all ok...\n");
  return 0;
}
