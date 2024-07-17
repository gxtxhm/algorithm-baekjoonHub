#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> m;
    for(int i=0;i<nums.size();i++)
    {
        // 못찾았다면
        if(m.find(nums[i])==m.end())
        {
            m.insert({nums[i],1});
        }
        else
            m[nums[i]]++;
    }
    for(int i=0;i<m.size();i++)
    {
        if(answer>=nums.size()/2)break;
        answer++;
        
    }
    return answer;
}