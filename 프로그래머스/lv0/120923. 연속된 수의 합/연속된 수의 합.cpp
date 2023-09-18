#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int arr[101]={0,};
    
    int a = total / num;
    
    while(true)
    {
        int sum = 0;
        for(int i=0;i<num;i++)
        {
            sum+=a-i;
            arr[i]= a-i;
        }
        if(sum==total)
        {
            for(int i=0;i<num;i++)
                answer.push_back(arr[i]);
            sort(answer.begin(),answer.end());
            break;
        }
        a++;
        
    }
    
    
    
    
    return answer;
}