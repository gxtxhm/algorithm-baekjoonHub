#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int a=0;
    int b=1;
    
    for(int i=2;i<=n;i++)
    {
        answer=(a%=1234567)+(b%=1234567);
        answer%=1234567;
        a=b;
        b=answer;
    }
    
    return answer;
}