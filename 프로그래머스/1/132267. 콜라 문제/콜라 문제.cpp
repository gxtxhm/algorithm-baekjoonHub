#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    int m=0;
    
    while(n+m>=a)
    {
        //1. 교환
        m+=(n/a)*b;
        answer+=(n/a)*b;
        n=n%a;
        
        //2. 마시기
        n+=m;
        m=0;
    }
    
    return answer;
}