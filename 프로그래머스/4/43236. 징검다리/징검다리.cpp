#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int func(int x,const vector<int>& arr)
{
    int cnt=0,s=0;
    for(int i=0;i<arr.size();i++)
    {
        s+=arr[i];
        if(s<x)
        {
            cnt++;
        }
        else
        {
            s=0;
        }
    }
    return cnt;
    
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(),rocks.end());
    vector<int> dist(rocks.size()+1);
    dist[0]=rocks[0];
    for(int i=1;i<dist.size()-1;i++)
        dist[i]=rocks[i]-rocks[i-1];
    dist[dist.size()-1]=distance-rocks[rocks.size()-1];
    int l=0,r=distance;
    
    while(l<=r)
    {
        int mid = (l+r)/2;
        int c= func(mid,dist);
        
        if(c<=n)
        {
            if(answer<mid)answer=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    
    return answer;
}