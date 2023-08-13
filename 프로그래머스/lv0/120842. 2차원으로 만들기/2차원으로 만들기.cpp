#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    int cnt=0;
    for(int i=0;i<num_list.size()/n;i++)
    {
        vector<int> b;
        for(int j=0;j<n;j++)
        {
            b.push_back(num_list[cnt]);cnt++;
        }
        answer.push_back(b);
    }
    
    return answer;
}