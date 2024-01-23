#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char buf[128]="name=xiongyongfeng";
putenv(buf);
char* p = getenv("name");
if(p==NULL)
  printf("not found\n");
else
  printf("%s\n",p);

strcpy(buf,"name=tiantan");
p = getenv("name");
if(p==NULL)
  printf("buf not found\n");
else
  printf("%s\n",p);
return 0;
}
