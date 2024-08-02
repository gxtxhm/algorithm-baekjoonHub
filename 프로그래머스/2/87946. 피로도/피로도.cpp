#include <string>
#include <vector>

using namespace std;

int maxCnt=-1;
vector<bool> ch(8,0);
int enterCnt=0;

void recur(int cnt,int curk,const vector<vector<int>>& dungeons)
{
    for(int i=0;i<dungeons.size();i++)
    {
        if(ch[i]==false&&curk>=dungeons[i][0])
        {
            enterCnt++;
            ch[i]=true;
            recur(cnt+1,curk-dungeons[i][1],dungeons);
            ch[i]=false;enterCnt--;
        }
    }
    if(enterCnt>maxCnt)
            maxCnt=enterCnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    recur(0,k,dungeons);
    return maxCnt;
}