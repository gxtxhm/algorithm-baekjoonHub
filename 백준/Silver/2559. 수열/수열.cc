#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    int start=0,end=0,sum=0,maxx=-10e7;
	while(end<n)
    {
        if(end-start < k)
            sum+=arr[end++];
        else
        {
            if(sum > maxx)maxx=sum;
            sum-=arr[start++];
        }
    }
    if(sum > maxx)maxx=sum;
    cout<<maxx;
	return 0;
}