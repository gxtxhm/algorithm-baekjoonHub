#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>, greater<int>> pq;
    
    for(int i=0;i<scoville.size();i++)
        pq.push(scoville[i]);
    
    int t1,t2;
    while(pq.size()>=2)
    {
        t1=pq.top();
        pq.pop();
        t2=pq.top();
        pq.pop();
        
        if(t1>=K && t2>=K)
            break;
        
        pq.push(t1+t2*2);
        answer++;
    }
    if(pq.top()<K)
        return -1;
    return answer;
}