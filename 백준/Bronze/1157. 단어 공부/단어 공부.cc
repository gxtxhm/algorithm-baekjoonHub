#include<stdio.h>
#include <string.h>
int main()
{
    int arr[26]={0,};
    
    char input[1000001];
    scanf("%s",input);
    
    int len=strlen(input);
    for(int i=0;i<len;i++)
    {
        int cmpV;
        if(input[i]>='a')
            ++arr[input[i]-97];
        else
            ++arr[input[i]-65];
    }
    int maxId=0;
    for(int i=0;i<26;i++)
    {
        if(arr[maxId] < arr[i])
            maxId=i;
    }
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        if(arr[maxId] == arr[i])
            cnt++;
    }
    if(cnt == 1)
        printf("%c",maxId+65);
    else
        printf("?");
    return 0;
}