#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    sort(lost.begin(),lost.end());
    vector<int> lost2;
    vector<int> arr(n+1,0);
    for(int i=0;i<reserve.size();i++)
    {
        arr[reserve[i]]=1;
    }
    for(int i=0;i<lost.size();i++)
    {
        if(arr[lost[i]]==1)arr[lost[i]]=0;
        else lost2.push_back(lost[i]);
    }
    for(int i=0;i<lost2.size();i++)
    {
        if(arr[lost2[i]]==1){
            arr[lost2[i]]=0;continue;
        }
        else
        {
            if(lost2[i]-1>=1&&arr[lost2[i]-1]==1){
                arr[lost2[i]-1]=0;continue;
            }
            if(lost2[i]+1<=n&&arr[lost2[i]+1]==1)
            {
                arr[lost2[i]+1]=0;continue;
            }
        }
        answer--;
    }
    
    return answer;
}