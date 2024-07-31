#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int num=0;
    int size = progresses.size();
    while(num<size)
    {
        if(progresses[num]<100)
        {
            for(int i=num;i<size;i++)
                progresses[i]+=speeds[i];
        }
        else
        {
            int cnt=0;
            for(int i=num;i<size;i++)
            {
                if(progresses[i]>=100)
                {
                    num++;
                    cnt++;
                }
                else
                {
                    num=i;
                    break;
                }
            }
            answer.push_back(cnt);
        }
    }
    
    return answer;
}