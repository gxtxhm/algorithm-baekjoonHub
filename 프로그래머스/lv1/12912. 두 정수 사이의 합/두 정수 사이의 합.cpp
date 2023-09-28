#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int min,max;
    
    min = (a>b)?b:a;
    max = (a>b)?a:b;
    
    for(int i=min;i<=max;i++)
        answer+=i;
    
    return answer;
}