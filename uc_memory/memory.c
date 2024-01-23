#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>

int main(void){
printf("pid:%d\n",getpid());
char* str1 ="hello beijing";
char* str2 ="hello beijing";

char buf[32];
strcpy(buf,"hello beijing");

printf("&str1=%p\n",&str1);
printf("&str2=%p\n",&str2);
printf("str1=%p\n",str1);
printf("str2=%p\n",str2);
printf("buf=%p\n",buf);
printf("str1=%s\n",str1);
printf("str2=%s\n",str2);
printf("buf=%s\n",buf);

getchar();
return 0;
}
