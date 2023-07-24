#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(int i=0;i<intStrs.size();i++)
    {
        int c;
        if(k<(c=stoi(intStrs[i].substr(s,l))))answer.push_back(c);
    }
    return answer;
}