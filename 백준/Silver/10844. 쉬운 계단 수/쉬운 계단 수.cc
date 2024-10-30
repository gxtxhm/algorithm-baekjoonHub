#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;cin>>n;
    
    vector<vector<int>> dy(n+1,vector<int>(10,0));
    for(int i=1;i<=9;i++)dy[1][i]=1;
    
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j==0)dy[i][j]=dy[i-1][j+1];
            else if(j==9)dy[i][j]=dy[i-1][j-1];
            else dy[i][j] = (dy[i-1][j-1]+dy[i-1][j+1])%1000000000;
            dy[i][j]=dy[i][j]%1000000000;
        }
    }
    int cnt=0;
    for(int i=0;i<=9;i++)cnt=(cnt+dy[n][i])%1000000000;
    cout<<cnt;
	return 0;
}