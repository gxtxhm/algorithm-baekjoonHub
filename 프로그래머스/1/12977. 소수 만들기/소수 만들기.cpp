#include <vector>
#include <iostream>
using namespace std;

bool isprim(int n)
{
    int cnt=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0){
            cnt++;
            if(i!=n/i)
                cnt++;
        }
    }
    if(cnt<=2)return true;
    else return false;
}

int solution(vector<int> nums) {
    int answer = 0;

    for(int i=0;i<nums.size()-2;i++)
    {
        for(int j=i+1;j<nums.size()-1;j++)
        {
            for(int k=j+1;k<nums.size();k++)
            {
                if(isprim(nums[i]+nums[j]+nums[k]))
                    answer++;
            }
        }
    }
    
    return answer;
}