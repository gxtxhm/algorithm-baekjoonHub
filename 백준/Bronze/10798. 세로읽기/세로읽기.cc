#include<iostream>
using namespace std;

int main()
{
    string arr[5];
    
    int maxLen = 0;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
        if(maxLen < arr[i].length())
        {
            maxLen = arr[i].length();
        }
    }
    for(int i=0;i<maxLen;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(arr[j].length()>i)
                cout<<arr[j][i];
        }
    }
    
    return 0;
}