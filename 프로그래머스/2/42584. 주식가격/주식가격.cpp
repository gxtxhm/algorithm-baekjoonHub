#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    stack<pair<int,int>> s;
    map<int,int> m;
    
    for(int i=0;i<prices.size();i++)
    {
        if(s.empty())
            s.push({i,prices[i]});
        else if(s.top().second<=prices[i])
            s.push({i,prices[i]});
        // 가격이 떨어진경우
        else
        {
            while(!s.empty() && s.top().second>prices[i])
            {
                auto& item = s.top();
                m[item.first]=i-item.first;
                s.pop();
            }
            s.push({i,prices[i]});
        }
    }
    while(!s.empty())
    {
        auto& item = s.top();
        m[item.first]=prices.size()-1 - item.first;
        s.pop();
    }
    for(auto& item : m)
        answer.push_back(item.second);
    return answer;
}