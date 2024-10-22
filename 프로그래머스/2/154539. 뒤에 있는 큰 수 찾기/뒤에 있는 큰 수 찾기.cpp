#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> s;
    answer.push_back(-1);
    s.push(numbers[numbers.size()-1]);
    for(int i=numbers.size()-2;i>=0;i--)
    {
        if(s.empty())
            answer.push_back(-1);
        else
        {
            while(!s.empty())
            {
                int cur = s.top();
                if(numbers[i]<cur){answer.push_back(cur);s.push(numbers[i]);break;}
                else s.pop();
                if(s.empty()){answer.push_back(-1);s.push(numbers[i]);break;}
            }
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}