#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=' ')
        {
            int al = (int)s[i];
            // 소문자이면
            if(al >= 97)
            {
                al = (al - 97 + n) % 26;
                s[i] = 'a'+al;
            }
            else
            {
                al = (al - 65 + n) % 26;
                s[i] = 'A' + al;
            }
            
            
        }
    }
    
    return s;
}