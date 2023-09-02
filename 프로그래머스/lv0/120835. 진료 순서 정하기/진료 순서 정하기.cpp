#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    int arr[101]={0,};
    
    for(int i=0;i<emergency.size();i++)
    {
        for(int j=0;j<emergency.size();j++)
        {
            if(emergency[i]<emergency[j])arr[emergency[i]]++;
        }
    }
    
    for(int i=0;i<emergency.size();i++)
        answer.push_back(arr[emergency[i]]+1);
    
    
    return answer;
}