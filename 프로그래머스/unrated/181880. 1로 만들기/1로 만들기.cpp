#include <string>
#include <vector>

using namespace std;

int solution(vector<int> n) {
    int answer = 0;
    for(int i=0;i<n.size();i++)
    {
        while(n[i]!=1)
        {
            if(n[i]%2==0)n[i]/=2;
            else (--n[i])/=2;
            answer++;
        }
    }
    return answer;
}