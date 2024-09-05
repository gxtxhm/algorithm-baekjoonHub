#include <string>
#include <vector>

using namespace std;

int answer=1500;
void recur(int t,int d,int i,int s,int size,vector<string>& minerals)
{
    if(size==minerals.size()||(d==0&&i==0&&s==0))
    {
        if(answer>t)answer=t;
        return;
    }
    int ct=0,curSize = (size+5>minerals.size())?minerals.size()-size:5;
    if(d>0)
    {
        for(int j=size;j<size+curSize;j++)
        {
            ct++;
        }
        recur(t+ct,d-1,i,s,size+curSize,minerals);
    }
    if(i>0)
    {
        ct=0;
        for(int j=size;j<size+curSize;j++)
        {
            if(minerals[j]=="diamond")ct+=5;
            else ct++;
        }
        recur(t+ct,d,i-1,s,size+curSize,minerals);
    }
    if(s>0)
    {
        ct=0;
        for(int j=size;j<size+curSize;j++)
        {
            if(minerals[j]=="diamond")ct+=25;
            else if(minerals[j]=="iron")ct+=5;
            else ct++;
        }
        recur(t+ct,d,i,s-1,size+curSize,minerals);
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    
    recur(0,picks[0],picks[1],picks[2],0,minerals);
    return answer;
}