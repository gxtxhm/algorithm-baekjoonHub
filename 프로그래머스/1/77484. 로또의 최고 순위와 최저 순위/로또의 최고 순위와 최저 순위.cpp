#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int cnt=0;
    int zeroCnt=0;
    for(int i=0;i<6;i++)
    {
        if(lottos[i]==0)
            zeroCnt++;
        for(int j=0;j<6;j++)
        {
            if(lottos[i]==win_nums[j])
                cnt++;
            
        }
    }
    
    int maxCnt = 7 - (cnt + zeroCnt);
    int minCnt = 7 - cnt;
    if(maxCnt>=7)maxCnt=6;
    if(minCnt>=7)minCnt=6;
    answer.push_back(maxCnt);
    answer.push_back(minCnt);
    
    return answer;
}