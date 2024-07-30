#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end(),greater<>());
    
    int num=citations[0];
    
    while(num>=0)
    {
        int cnt=0;
        for(int j=0;j<citations.size();j++)
        {
            if(citations[j]>=num)
                cnt++;
        }
        if(cnt>=num)
            return num;
        
        num--;
    }
    
    return answer;
}