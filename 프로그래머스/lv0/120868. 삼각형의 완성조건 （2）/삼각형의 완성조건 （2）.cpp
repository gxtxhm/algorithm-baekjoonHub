#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    // 나머지가 가장 길 경우
    int small = (sides[0]>sides[1])?sides[1]:sides[0];
    int big = (sides[0]<sides[1])?sides[1]:sides[0];
    
    for(int i=big;i<small+big;i++)
    {
        answer++;
    }
    
    // 나머지가 가장 길지 않을 때
    for(int i=big-small+1;i<big;i++)
    {
        if(big<=small+i)answer++;
    }
    
    
    return answer;
}