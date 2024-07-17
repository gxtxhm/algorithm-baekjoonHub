#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a1[5]={1,2,3,4,5};
    int a2[8]={2,1,2,3,2,4,2,5};
    int a3[10]={3,3,1,1,2,2,4,4,5,5};
    
    int cnt1=0,cnt2=0,cnt3=0;
    int id1=0,id2=0,id3=0;
    
    for(int i=0;i<answers.size();i++)
    {
        if(answers[i]==a1[id1])
            cnt1++;
        if(answers[i]==a2[id2])
            cnt2++;
        if(answers[i]==a3[id3])
            cnt3++;
        id1= (id1+1)%5;
        id2= (id2+1)%8;
        id3= (id3+1)%10;
    }
    int maxCnt = (cnt1 < cnt2)? max(cnt2,cnt3):max(cnt1,cnt3);
    if(maxCnt==cnt1)
        answer.push_back(1);
    if(maxCnt==cnt2)
        answer.push_back(2);
    if(maxCnt==cnt3)
        answer.push_back(3);
    
    return answer;
}