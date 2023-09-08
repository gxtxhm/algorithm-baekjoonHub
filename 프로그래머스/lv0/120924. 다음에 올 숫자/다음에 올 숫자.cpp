#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    bool ch=false;
    int d;
    if(common[1]-common[0]==common[2]-common[1])
    {
        ch=false;
        d=common[1]-common[0];
    }
    else 
    {
        ch=true;
        d=common[1]/common[0];
    }
    answer=common[common.size()-1];
    if(ch)
    {
        answer*=d;
    }
    else
        answer+=d;
    
    
    return answer;
}