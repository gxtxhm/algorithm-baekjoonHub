#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

bool compare(const pair<string,vector<string>>& a,const pair<string,vector<string>>& b)
{
    if(a.second[0]!=b.second[0])
        return a.second[0]<b.second[0];
    else
        return stoi(a.second[1])<stoi(b.second[1]);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string,vector<string>>> data;
    int idx=0;
    for(int i=0;i<files.size();i++)
    {
        vector<string> v(3);
        string t="";
        int j=0;
        for(j = 0;j<files[i].length();j++)
        {
            if(isdigit(files[i][j]))break;
            t+=tolower(files[i][j]);
        }
        v[0]=t;t="";
        int cnt=0;
        for(;cnt<5&&j<files[i].length();j++,cnt++)
        {
            if(!isdigit(files[i][j]))break;
            t+=files[i][j];
        }
        v[1]=t;
        v[2]= "";
        data.push_back({files[i],v});
    }
    
    stable_sort(data.begin(),data.end(),compare);
    for(int i=0;i<data.size();i++)
        answer.push_back(data[i].first);
    return answer;
}