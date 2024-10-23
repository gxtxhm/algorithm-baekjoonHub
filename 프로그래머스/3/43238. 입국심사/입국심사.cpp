#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long countPeople(long long time, const vector<int>& times)
{
    long long total=0;
    for(int i : times)
    {
        total += time/i;
    }
    return total;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long l = 1;
    long long r = times[times.size()-1] * (long long)n;
    //long long r = 1e18;
    answer = r;
    while(l<=r)
    {
        long long mid = (l+r)/2;
        
        if(countPeople(mid,times)>=n)
        {
            if(answer>mid)answer=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return answer;
}