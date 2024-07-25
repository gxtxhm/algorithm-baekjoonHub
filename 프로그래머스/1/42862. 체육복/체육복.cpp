#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> arr(n+1,0);
    
    for(int i=0;i<lost.size();i++)arr[lost[i]]=-1;
    for(int i=0;i<reserve.size();i++){
        if(arr[reserve[i]]==-1)
            arr[reserve[i]]=0; // 여벌을 가져왔지만 도난당함
        else
            arr[reserve[i]]=1;
    }
    
    for(int i=1;i<n+1;i++)
    {
        if(arr[i]==-1)
        {
            if(i-1>0&&arr[i-1]==1)
            {
                arr[i]=0;
                arr[i-1]=0;
            }
            else if(i+1<n+1&&arr[i+1]==1)
            {
                arr[i]=0;arr[i+1]=0;
            }        
        }
    }
    for(int i=1;i<n+1;i++)
        if(arr[i]!=-1)
            answer++;
    return answer;
}