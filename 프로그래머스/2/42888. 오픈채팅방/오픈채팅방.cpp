#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<char,string>> v;
    unordered_map<string,string> um;
    
    for(int i=0;i<record.size();i++)
    {
        if(record[i][0]=='L')
        {
            string uid=record[i].substr(6);
            v.push_back({'L',uid});
        }
        else
        {
            if(record[i][0]=='C')
            {
                string temp=record[i].substr(7);
                int idx = temp.find(' ');
                string uid=temp.substr(0,idx);
                string nick = temp.substr(idx+1);
                um[uid]=nick;
            }
            else
            {
                string temp=record[i].substr(6);
                int idx = temp.find(' ');
                string uid=temp.substr(0,idx);
                string nick = temp.substr(idx+1);
                um[uid]=nick;
                v.push_back({'E',uid});
            }
        }
    }
    
    for(int i=0;i<v.size();i++)
    {
        string s="";
        s+=um[v[i].second];
        if(v[i].first=='L')
            s+="님이 나갔습니다.";
        else if(v[i].first=='E')
            s+="님이 들어왔습니다.";
        answer.push_back(s);
    }
    return answer;
}