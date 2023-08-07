#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int row = arr.size();
    int col = arr[0].size();

    int gap = (row < col)? col - row : row - col;

    if(row < col)
    {
        for(int j=0;j<col-row;j++)
        {
            vector<int> a;
            for(int i=0;i<col;i++)
                a.push_back(0);
            arr.push_back(a);
        }
    }
    else
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<row-col;j++)
            {
                arr[i].push_back(0);
            }

        }
    }

    return arr;
}