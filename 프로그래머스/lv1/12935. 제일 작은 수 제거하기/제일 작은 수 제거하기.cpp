#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min=2100000000;
    int minId;
    for(int i=0;i<arr.size();i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
            minId=i;
        }
    }
    
    arr.erase(arr.begin()+minId);
    if(arr.size()==0)
        arr.push_back(-1);
    return arr;
}