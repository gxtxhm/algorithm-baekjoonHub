#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i;
    for(i=1;answer<n;)
    {
        if(i%3!=0)
        {
            int j=i;
            while(j>0)
            {
                if(j%10==3)break;
                j/=10;
            }
            if(j==0)answer++;
        }
        i++;
    }
    
    return i-1;
}