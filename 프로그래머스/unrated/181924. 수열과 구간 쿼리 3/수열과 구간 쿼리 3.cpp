#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> q) {
    vector<int> answer;
    for(int i=0;i<q.size();i++)
    {
        int c = arr[q[i][0]];
        arr[q[i][0]]=arr[q[i][1]];
        arr[q[i][1]]=c;
    }
    return arr;
}