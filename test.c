#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<unistd.h>
int main()
{
    long int res=syscall(358);
    long int res2=syscall(359,"/home/songchujun/Desktop/syscall/copy.c","/home/songchujun/Desktop/syscall/copyy.c");
    printf("res=%ld\n",res);
    printf("res=%ld\n",res2);
    return 0;
}
