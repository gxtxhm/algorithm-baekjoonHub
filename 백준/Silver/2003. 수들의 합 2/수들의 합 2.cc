#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m;cin>>n>>m;
    int sum=0, ans=0;
    int fIdx=0;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        if(sum == m){ans++;}
        
        while(sum >= m && fIdx <=i)
        {
            sum-=arr[fIdx];fIdx++;
            if(sum==m)ans++;
        }
        
    }
    for(int i=fIdx;i<n;i++)
    {
        sum-=arr[fIdx];
        if(sum==m)ans++;
        if(sum < m)break;
    }
	cout<<ans;
	return 0;
}