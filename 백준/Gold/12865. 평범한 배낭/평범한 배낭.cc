#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,k;cin>>n>>k;
    vector<pair<int,int>> arr(n+1);
    vector<vector<int>> dy(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++)
    {
        int w,v;cin>>w>>v;
        arr[i]={w,v};
    }
	sort(arr.begin(),arr.end());
    
    int res=0;
    for(int i=1;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].first;j++)dy[i][j]=dy[i-1][j];
        for(int j=arr[i].first;j<=k;j++)
        {
             dy[i][j] = max(dy[i-1][j],dy[i-1][j-arr[i].first]+arr[i].second);   
            if(res < dy[i][j])res=dy[i][j];
        }
    }
    
    cout<<dy[n][k];
	return 0;
}