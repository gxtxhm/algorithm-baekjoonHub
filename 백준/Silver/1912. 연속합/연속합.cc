#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;cin>>n;
    vector<int>arr;
    vector<int>dy(n+1,0);
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        arr.push_back(a);
    }
    dy[0]=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<=dy[i-1]+arr[i])dy[i]=dy[i-1]+arr[i];
        else dy[i]=arr[i];
        
    }
    int res=dy[0];
    for(int i=0;i<n;i++)
    {
        if(res<dy[i])res=dy[i];
    }
    cout<<res;
    return 0;
}