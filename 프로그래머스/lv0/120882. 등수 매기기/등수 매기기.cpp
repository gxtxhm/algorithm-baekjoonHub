#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size(),1);
    
    for(int i=0;i<score.size();i++)
    {
        int t = score[i][0]+score[i][1];
        for(int j=0;j<score.size();j++)
        {
            if(t>(score[j][0]+score[j][1]))
                answer[j]++;
        }
    }
    
    return answer;
}