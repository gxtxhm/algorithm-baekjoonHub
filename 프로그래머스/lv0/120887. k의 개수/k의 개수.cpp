#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for(int u=i;u<=j;u++)
    {
        int c=u;
        while(c>0)
        {
            if(c%10==k)answer++;
            c/=10;
        }
    }
    
    return answer;
}