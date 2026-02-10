#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");return 0;
    }
    int res=1,j=6,maxV=1;
    while(n>maxV)
    {
        res++;maxV+=j;j+=6;
    }
    printf("%d",res);
    
    return 0;
}