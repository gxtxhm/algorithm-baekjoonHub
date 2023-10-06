#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long a = num;
    while(true)
    {
        if(a==1)break;
        
        if(a%2==0)a/=2;
        else a=a*3+1;
        answer++;
        if(answer==500)
            return -1;
    }
    
    return answer;
}