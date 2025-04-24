#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> arr;
    for(int i=0;i<score.size();i++)
    {
        arr.push_back(score[i]);
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i=arr.size()-m;i>=0;i-=m)
    {
        answer+=arr[i]*m;
    }
    
    return answer;
}