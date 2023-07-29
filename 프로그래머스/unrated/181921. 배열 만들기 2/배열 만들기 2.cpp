#include <string>
#include <vector>

using namespace std;

bool check(int num)
{
    while(num)
    {
        if(num % 10 != 0 && num % 10 != 5)
            return false;
        num /= 10;
    }
    return true;
}
vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i=l; i<=r; i++)
    {
        if(check(i))
            answer.push_back(i);
    }
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}

