#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    while(true)
    {
        answer+=6;
        if(answer%n==0)break;
    }
    
    return answer/6;
}