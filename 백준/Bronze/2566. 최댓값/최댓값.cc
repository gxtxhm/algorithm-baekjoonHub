#include<iostream>

using namespace std;

int main()
{
    int maxV=-1;
    int r,c;
    int input;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>input;
            if(maxV < input)
            {
                maxV = input;
                r = i;
                c = j;
            }
        }
    }
    cout<<maxV<<endl;
    cout<<r+1;cout<<" ";cout<<c+1;
    return 0;
}