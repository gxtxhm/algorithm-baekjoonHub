#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> dy(k+1,0);
	
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dy[0]=1;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i];j<=k;j++)
        {
            dy[j] = dy[j] + dy[j-arr[i]];
            
        }
    }
    cout<<dy[k];
	return 0;
}