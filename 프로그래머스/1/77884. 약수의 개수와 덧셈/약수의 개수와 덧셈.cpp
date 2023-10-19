#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left;i<=right;i++)
    {
        // 약수 개수 구하기
        int cnt=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
                cnt++;
        }
        if(cnt%2==0)
            answer+=i;
        else
            answer-=i;
    }
    
    return answer;
}