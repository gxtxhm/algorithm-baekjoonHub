#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void recur(vector<unordered_map<string,int>>& data, int len,string s,int idx,string curS)
{
    if(len == s.length()|| curS[curS.length()-1]==s[s.length()-1])
        return;
    
    for(int i=idx;i<s.length();i++)
    {
        curS+=s[i];
        data[curS.length()][curS]++;
        recur(data,curS.length(),s,i+1,curS);
        curS.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<unordered_map<string,int>> data(11);
    
    for(int i=0;i<orders.size();i++)
    {
        sort(orders[i].begin(),orders[i].end());
        recur(data,0,orders[i],0,"");
    }
    
    for(int i=0;i<course.size();i++)
    {
        int max=-1;
        for(auto& item : data[course[i]])
        {
            if(item.second>=2&&item.second>max)
            {
                max=item.second;
            }
        }
        for(auto& item : data[course[i]])
            if(item.second==max)
                answer.push_back(item.first);
    }
    stable_sort(answer.begin(),answer.end());
    return answer;
}