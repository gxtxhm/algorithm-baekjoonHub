#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int maxId=0;
    vector<bool> b(priorities.size(),0);
    // 반복해서 startIdx 와 location이 같으면 종료
    while(true)
    {
        // 가장 큰 수를 찾아서 maxIdx 로 세팅
        for(int i=maxId,cnt=0;cnt<priorities.size();i=(i+1)%priorities.size(),cnt++)
        {
            if(b[i]==false && priorities[maxId]<priorities[i])
                maxId=i;
        }
        // cnt 1 증가시키기 
        answer++;
        b[maxId]=true;
        if(maxId==location)
            break;
        maxId = (maxId+1)%priorities.size();
        while(b[maxId])
            maxId = (maxId+1)%priorities.size();
    }
    
    return answer;
}