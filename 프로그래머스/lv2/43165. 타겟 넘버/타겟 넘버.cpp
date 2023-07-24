#include <string>
#include <vector>

using namespace std;

int cnt=0;

void D(int target,vector<int>num,int n,int i)
{
    if(i==num.size())
    {
        if(n==target)cnt++;
        return;
    }
    
    
    D(target,num,n+num[i],i+1);
    D(target,num,n-num[i],i+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    D(target,numbers,0,0);
    return cnt;
}