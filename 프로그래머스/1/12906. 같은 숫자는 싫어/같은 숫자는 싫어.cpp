#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int s=arr[0];
    answer.push_back(s);
    for(int i=1;i<arr.size();i++)
    {
        if(s!=arr[i])
        {
            answer.push_back(arr[i]);
        }
        s=arr[i];
    }

    return answer;
}