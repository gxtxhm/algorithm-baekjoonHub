#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;cin>>n;
    vector<int> dy(n+1,10e6+1);
    dy[0]=0;dy[1]=0;dy[2]=1;dy[3]=1;
    
    for(int i=4;i<=n;i++)
    {
        if(i%3==0)dy[i]=dy[i/3]+1;
        if(i%2==0)dy[i]=min(dy[i],dy[i/2]+1);
        dy[i]= min(dy[i],dy[i-1]+1);
    }
    cout<<dy[n];
	return 0;
}