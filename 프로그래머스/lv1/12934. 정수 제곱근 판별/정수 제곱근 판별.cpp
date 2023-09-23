#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long a = sqrt(n);
    
    for(long long i = 0; i<=a;i++)
    {
        if(i*i==n)
        {
            return (i+1)*(i+1);
        }
    }
    
    return -1;
}