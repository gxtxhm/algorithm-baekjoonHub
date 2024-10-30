#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;cin>>n;
    
    int x = n/5;
    int y = n%5;
    
    if(y==0)cout<<x;
    else 
    {
        if(y%3==0)
        {
            cout<<x+(y/3);return 0;
        }
        else
        {
            while(x>0)
            {
                y+=5;x--;
                if(y%3==0)
                {
                    cout<<x+y/3;return 0;
                }
            }
        }
        cout<<-1;
    }
    
	return 0;
}