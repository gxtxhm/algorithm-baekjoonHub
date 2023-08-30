#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string my_string) {
    string answer = "";
    map<char,bool> m;
    
    for(int i=0;i<my_string.length();i++)
    {
        if(m.find(my_string[i])==m.end())
        {
            answer+=my_string[i];
            m.insert({my_string[i],true});
        }
    }
    
    return answer;
}