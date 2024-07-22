#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int> m;
    int year = stoi(today.substr(0,4));
    int month = stoi(today.substr(5,2));
    int day = stoi(today.substr(8));
    
    for(int i=0;i<terms.size();i++)
    {
        m.insert({terms[i][0],stoi(terms[i].substr(2))});
    }
    
    for(int i=0;i<privacies.size();i++)
    {
        // 수집한 날짜
        int my = stoi(privacies[i].substr(0,4));
        int mm = stoi(privacies[i].substr(5,2));
        int md = stoi(privacies[i].substr(8,2));
        
        char type = privacies[i][11];
        
        // 유효기간
        int ty = my;
        int tm = mm + m[type];
        int td = md;
        td--;
        if(td<=0)
        {
            td=28;
            tm--;
            if(tm<=0)
            {
                tm=12;
                ty--;
            }
        }
        
        while(tm>12)
        {
            tm-=12;
            ty++;
        }
        
        if(year>ty)answer.push_back(i+1);
        else if(year==ty)
        {
            if(month>tm)answer.push_back(i+1);
            else if(month==tm)
            {
                if(day>td)answer.push_back(i+1);
            }
            
        }
    }
    
    return answer;
}