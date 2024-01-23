#include<stdio.h>

#include <t_file.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
  //int flags = O_WRONLY | O_CREAT | O_TRUNC;
  int flags = O_WRONLY | O_CREAT | O_EXCL;
  int fd = open(argv[1],flags,0644);
  if(fd==-1){
    printf("can not open file: %s\n",strerror(errno));
    return -1;
  }

    printf("open file successfully\n");
    close(fd);
  return 0;
}
