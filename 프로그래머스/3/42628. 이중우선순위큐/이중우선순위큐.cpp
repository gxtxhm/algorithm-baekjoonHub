#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer={0,0};
    unordered_map<int,int> us;
    priority_queue<int> sa;// 내림
    priority_queue<int,vector<int>,greater<int>> sb;// 올림
    
    for(string& s : operations)
    {
        istringstream iss(s);
        string a,b;
        iss>>a;
        iss>>b;
        if(a[0]=='I')
        {
            int im = stoi(b);
            us[im]++;
            sa.push(im);
            sb.push(im);
        }
        else
        {
            if(us.empty())
                continue;
            if(b=="1")
            {
                while(!sa.empty()&&us.find(sa.top())==us.end())
                    sa.pop();
                us[sa.top()]--;
                if(us[sa.top()]==0)
                    us.erase(sa.top());
                sa.pop();
            }
            else
            {
                while(!sb.empty()&&us.find(sb.top())==us.end())
                    sb.pop();
                us[sb.top()]--;
                if(us[sb.top()]==0)
                    us.erase(sb.top());
                sb.pop();
            }
        }
    }
    while(!sa.empty()&&us.find(sa.top())==us.end())sa.pop();
    while(!sb.empty()&&us.find(sb.top())==us.end())sb.pop();
    if(!us.empty())
    {
        answer[0]=sa.top();
        answer[1]=sb.top();
    }
    return answer;
}