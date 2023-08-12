#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int f=1;
    while(n>=f)
    {
        answer++;
        f*=answer;
        
    }
    return answer-1;
}