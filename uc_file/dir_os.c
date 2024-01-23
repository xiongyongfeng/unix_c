#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <error.h>
#include <dirent.h>
typedef struct dirent Dirent;
int main(int argc, char* argv[])
{
  DIR *dir=opendir(argv[1]);
  if(dir==NULL){perror("opendir");return -1;}
  Dirent* sd;
  while((sd=readdir(dir))!=NULL)
    printf("file is %s, inode number is %lu\n",sd->d_name,sd->d_ino);

  closedir(dir);
return 0;
}
