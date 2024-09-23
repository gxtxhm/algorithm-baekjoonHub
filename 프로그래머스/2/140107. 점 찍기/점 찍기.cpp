#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int x=0;x<=d;x+=k)
    {
        int mayY = sqrt((long long)d*d - (long long)x*x);
        answer += mayY/k + 1;
    }
    return answer;
}