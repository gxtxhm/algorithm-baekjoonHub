#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    while(order>0)
    {
        int o = order%10;
        if(o==3||o==6||o==9)answer++;
        order/=10;
    }
    return answer;
}