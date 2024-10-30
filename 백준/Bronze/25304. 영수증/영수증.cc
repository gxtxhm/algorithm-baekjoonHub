#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,x;cin>>x>>n;
    
    for(int i=0;i<n;i++)
    {
        int a,b;cin>>a>>b;
        x-=a*b;
    }
	cout<<((x==0)?"Yes" : "No");
	return 0;
}