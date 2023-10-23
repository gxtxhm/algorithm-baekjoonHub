#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    string a="";
    
    while(n>0)
    {
        a+=(char)(n%3);
        n/=3;
    }
    
    answer=0;
    int pow=1;
    for(int i=a.length()-1;i>=0;i--)
    {
        answer += (int)a[i]*pow;
        pow*=3;
    }
    
    return answer;
}