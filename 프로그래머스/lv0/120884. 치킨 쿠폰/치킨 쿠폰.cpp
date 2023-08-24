#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    
    int cnt=chicken;
    while(cnt>=10)
    {
        answer+=cnt/10;
        cnt = cnt % 10 + cnt/10;
    }
    
    return answer;
}