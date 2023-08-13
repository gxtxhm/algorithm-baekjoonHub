#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    vector<vector<int>> a (100,vector<int>());
    
    for(int i=0;i<array.size();i++)
    {
        a[abs(n-array[i])].push_back(array[i]);
    }
    
    for(int i=0;i<100;i++)
    {
        if(a[i].size()!=0)
        {
            sort(a[i].begin(),a[i].end());
            return a[i][0];
        }
    }
    
    return answer;
}