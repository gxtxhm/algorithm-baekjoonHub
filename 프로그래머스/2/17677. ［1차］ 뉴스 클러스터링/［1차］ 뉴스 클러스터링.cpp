#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

unordered_map<string,int> make_map(const string& str)
{
    unordered_map<string,int> um;
    
    for(int i=0;i<str.length()-1;i++)
    {
        if(isalpha(str[i])&&isalpha(str[i+1]))
        {
            string s = {(char)tolower(str[i]),(char)tolower(str[i+1])};
            um[s]++;
        }
    }
    return um;
}

int solution(string str1, string str2) {

    unordered_map<string,int> um1 = make_map(str1);
    unordered_map<string,int> um2 = make_map(str2);    
    
    int intersectionSize=0;
    int unionSize=0;
    
    for(auto& item : um1)
    {
        auto it = um2.find(item.first);
        // 찾았다면 
        if(it!=um2.end())
        {
            intersectionSize += min(item.second,um2[item.first]);
            unionSize += max(item.second,um2[item.first]);
            um2.erase(it);
        }
        else
            unionSize += item.second;
    }
    
    for(const auto& item : um2)
    {
        unionSize+=item.second;
    }
    if(unionSize==0)return 65536;
    return static_cast<int>(static_cast<double>(intersectionSize)/unionSize*65536);
}