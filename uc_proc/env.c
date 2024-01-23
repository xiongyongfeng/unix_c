#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

extern char* environ;
int main(int argc, char* argv[]){
char* path;
if(argc<2)
{
path = getenv("caption");
}
else
{
path = getenv(argv[1]);
}


if(path==NULL)
{
printf("not found...\n");
}
else
{
	printf("env:%s\n",path);
}
setenv("caption","nanjing",0);
path = getenv("caption");
if(path==NULL)
{
printf("setenv fail...\n");
}
else
{
	printf("env:%s\n",path);
}
unsetenv("caption");
path = getenv("caption");
if(path==NULL)
{
printf("unsetenv not found...\n");
}
else
{
	printf("unsetenv:%s\n",path);
}
clearenv();
if(environ==NULL)
  printf("clear env list..\n");
return 0;
}
