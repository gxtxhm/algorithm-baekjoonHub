#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    bool arr[100][100]={false,};
    
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        for(int r=0;r<10;r++)
        {
            for(int c=9;c>=0;c--)
            {
                arr[r+a][c+b]=true;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(arr[i][j])cnt++;
        }
    }
    cout<<cnt;
    
    return 0;
}