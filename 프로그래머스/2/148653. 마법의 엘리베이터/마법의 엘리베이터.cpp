#include <string>
using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey>0)
    {
        int im = storey%10;
        storey/=10;
        int next = storey%10;
        if(im>5||(im==5 && next >= 5))
        {
            storey++;
            answer+=(10-im);
        }
        else
            answer+=im;
    }
    return answer;
}