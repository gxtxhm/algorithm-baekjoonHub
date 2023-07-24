#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> q) {
    
    for(int i=0;i<q.size();i++)
    {
        for(int j=q[i][0];j<=q[i][1];j++)
        {
            arr[j]++;
        }
    }
    
    return arr;
}