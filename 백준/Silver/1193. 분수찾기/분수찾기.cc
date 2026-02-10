#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int first,second,j=1,maxV=1;
    
    while(n>maxV)
    {
        j++;
        maxV+=j;
    }
    int addV;
    if(j%2==0)
    {
        first=1;second=j;addV=1;
    }
    else
    {
        first=j;second=1;addV=-1;
    }

    for(int i=maxV-j+1;i<=maxV;i++)
    {
        if(i==n)break;
        first+=addV;second+=addV*-1;
    }
    printf("%d/%d",first,second);
    
    return 0;
}