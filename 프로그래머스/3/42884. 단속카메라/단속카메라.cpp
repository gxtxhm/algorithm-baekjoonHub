#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(),routes.end(),compare);
    
    answer=1;
    int before=routes[0][1];
    // 카메라 설치지점에 포함안되면 설치를 다시 [1]에 하기
    for(int i=1;i<routes.size();i++)
    {
        if(before<routes[i][0])
        {
            answer++;
            before= routes[i][1];
        }
    }
    return answer;
}