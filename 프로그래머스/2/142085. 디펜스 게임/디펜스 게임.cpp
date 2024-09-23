#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>,greater<int>> pq;
    int total_damage=0;
    
    for(int i=0;i<enemy.size();i++)
    {
        pq.push(enemy[i]);
        
        if(pq.size()>k)
        {
            total_damage+=pq.top();
            pq.pop();
        }
        
        if(total_damage>n)
            return i;
    }
    
    return enemy.size();
}