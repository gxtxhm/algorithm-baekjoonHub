#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string,vector<string>> reportList;
    map<string,int> num;
    
    for(int i=0;i<id_list.size();i++)
    {
        num.insert({id_list[i],0});
        vector<string> a;
        reportList.insert({id_list[i],a});
    }
    for(int i=0;i<report.size();i++)
    {
        int idx = report[i].find(' ');
        string a = report[i].substr(0,idx);
        string b = report[i].substr(idx+1);
        
        bool t = true;
        for(int j=0;j<reportList[a].size();j++)
        {
            if(reportList[a][j]==b)
            {
                t=false;break;
            }
        }
        if(t)
        {
            reportList[a].push_back(b);
            num[b]++;
        }
        
    }
    
    for(int i=0;i<id_list.size();i++)
    {
        int cnt=0;
        for(int j=0;j<reportList[id_list[i]].size();j++)
        {
            if(num[reportList[id_list[i]][j]]>=k)
                cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}