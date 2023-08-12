#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    int cnt=1;
    while(num>0)
    {
        if(num%10==k)answer=cnt;
        cnt++;
        num/=10;
    }
    if(answer!=-1)answer = cnt - answer;
    return answer;
}