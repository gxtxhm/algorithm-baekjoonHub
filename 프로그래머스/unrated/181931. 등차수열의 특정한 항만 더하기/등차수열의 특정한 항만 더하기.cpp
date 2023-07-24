#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    int c=a;
    if(included[0])answer+=a;
    for(int i=1;i<included.size();i++)
    {
        c+=d;
        if(included[i])answer+=c;
    }
    return answer;
}