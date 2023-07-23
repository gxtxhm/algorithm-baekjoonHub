#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = 0;
    
    for(int i=0;i<=arr.size()/2;i++)
    {
        for(int j=0;j<=arr.size()/2;j++)
        {
            if(arr[i][j]!=arr[j][i])return 0;
        }
    }
    return 1;
}