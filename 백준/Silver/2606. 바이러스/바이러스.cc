#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,num;cin>>num>>n;
    vector<bool> ch(num+1,false);
    
    vector<vector<int>> graph(num+1,vector<int>());
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
	
    queue<int>q;
    q.push(1);
    ch[1]=true;
    while(!q.empty())
    {
        int x = q.front();q.pop();
        for(int i=0;i<graph[x].size();i++)
        {
            if(ch[graph[x][i]]==false)
            {
                q.push(graph[x][i]);ch[graph[x][i]]=true;
            }
        }
    }
    int cnt=0;
    for(int i=2;i<=num;i++)
        if(ch[i]==true)cnt++;
    cout<<cnt;
	return 0;
}