#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int i=0;i<arr.size();i++)
    {
        if(answer.size()==0)answer.push_back(arr[i]);
        else if(answer[answer.size()-1]==arr[i])
        {
            // 마지막 원소 제거 
            answer.erase(answer.begin()+answer.size()-1);
        }
        else
        {
            answer.push_back(arr[i]);
        }
    }
    
    if(answer.empty())answer.push_back(-1);
    return answer;
}