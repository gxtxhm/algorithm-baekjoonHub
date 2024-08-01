#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string,bool>um;
    for(int i=0;i<phone_book.size();i++)
        um.insert({phone_book[i],true});
    
    for(int i=0;i<phone_book.size();i++)
    {
        string cur = phone_book[i];
        string temp="";
        for(int j=0;j<cur.length();j++)
        {
            temp+=cur[j];
            if(um[temp]&&cur!=temp)
                return false;
        }
    }
    
    return answer;
}