#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int max_day=0;
    
    for(int i=0;i<progresses.size();i++)
    {
        // 100 일 때는 나머지가 0인지 아닌지에 따라 나누지만 99로 하면 무조건 +1을
        // 해야함
        // day는 현재 작업이 완료되기까지의 일 수
        int day = (99-progresses[i]) / speeds[i] + 1;    
        
        // 빈 경우는 맨처음, max_day는 지금 이 작업이 배포되려면 며칠을 기다려야하는지
        if(answer.empty() || max_day < day)
            answer.push_back(1);
        else
        // max_day보다 day가 작으면 이미 작업이 완료된 상태이기 때문에 배포수 + 1
            answer.back()++;
        
        // day가 더 크면 이전까지의 작업은 다 배포완료되었고 지금 i번째 작업이 완료되기를
        // 기다려야한다.
        if(max_day<day)
            max_day = day;
    }
    
    return answer;
}