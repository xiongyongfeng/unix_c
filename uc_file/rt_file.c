#include<stdio.h>

#include <t_file.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
  int fd = open(argv[1],O_RDONLY);
  if(fd==-1){
    printf("can not open file: %s\n",strerror(errno));
    return -1;
}

    printf("open file successfully\n");
    close(fd);
  return 0;
}
