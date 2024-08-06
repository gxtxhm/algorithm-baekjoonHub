#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i=0;i<arr1.size();i++)
    {
        vector<int> a;
        for(int j=0;j<arr2[0].size();j++)
        {
            // 만들어질 행렬의 한 원소
            // i = 행 , j = 열, answer[i][j]
            int sum = 0;
            for(int k=0;k<arr2.size();k++)
                sum+=arr1[i][k]*arr2[k][j];
            a.push_back(sum);
        }
        answer.push_back(a);
    }
    
    return answer;
}