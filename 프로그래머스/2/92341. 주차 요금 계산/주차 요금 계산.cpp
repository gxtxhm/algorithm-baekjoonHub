#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,bool> states;// in인지 out인지
    map<string,int> times;// 누적시간
    map<string, int> curTime;// in이라면 몇시에 in했는지
    int maxTime = 1439;
    
    for(int i=0;i<records.size();i++)
    {
        string time = records[i].substr(0,5);
        string id = records[i].substr(6,4);
        string state = records[i].substr(11);
        
        if(state=="IN")
        {
            states[id]=true;
            int t=stoi(time.substr(0,2))*60 + stoi(time.substr(3));
            curTime[id]=t;
            if(times.find(id)==times.end())
                times[id]=0;
        }
        else
        {
            states[id]=false;
            int t = stoi(time.substr(0,2))*60 + stoi(time.substr(3)) - curTime[id];
            times[id] += t;
        }
    }
    
    for(auto& item : times)
    {
        // 출차되지 않은차
        if(states[item.first])
            times[item.first]+=maxTime - curTime[item.first];
        
        int sum = fees[1];
        if(times[item.first]>fees[0])
        {
            int it;
            if(((times[item.first]-fees[0])%fees[2])==0)
                it = ((times[item.first]-fees[0])/fees[2]);
            else
                it = ((times[item.first]-fees[0])/fees[2])+1;
            sum+= it * fees[3];
        }
        answer.push_back(sum);
    }
    
    return answer;
}