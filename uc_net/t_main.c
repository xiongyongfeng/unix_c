#include "t_main.h"
#include<unistd.h>
#include<ctype.h>
int t_main(int fd)
{
  char buf[128];
  int r = read(fd,buf,128);
  for(int i = 0; i<r;i++)
    buf[i] =  toupper(buf[i]);
  write(fd,buf,r);
  return 0;
}
