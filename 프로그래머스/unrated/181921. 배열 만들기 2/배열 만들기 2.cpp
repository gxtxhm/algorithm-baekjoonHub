#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i=l;i<=r;i++)
    {
        if(i%5==0)
        {
            string s = to_string(i);
            bool ch = false;
            for(int j=0;j<s.length();j++)
            {
                if(s[j]!='5'&&s[j]!='0'){
                    ch=true;
                    break;
                }
            }
            if(ch==false)answer.push_back(i);
        }
    }
    
    if(answer.size()==0)answer.push_back(-1);
    return answer;
}