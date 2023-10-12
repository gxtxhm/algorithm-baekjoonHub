#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.length()==4 || s.length()==6)
    {
        bool c = true;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<48||s[i]>57)
            {
                c = false;
                break;
            }
        }
        if(c==false)
            return false;
    }
    else
    {
        return false;
    }
    
    return true;
}