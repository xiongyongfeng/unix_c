#include<stdio.h>
#include<unistd.h>
   int main(void)
   {
     unsigned int sec = alarm(7);
     for(int i = 1;i<2400000;i++)
       printf("i=%d\n",i);
     sec = alarm(0);
     printf("sec=%d\n",sec);
     return 0;
 }
