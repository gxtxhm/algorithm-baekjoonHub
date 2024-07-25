#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    vector<int>arr(board.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (board[j][i] != 0)
            {
                arr[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < moves.size(); i++)
    {
        moves[i]--;
        if (arr[moves[i]] == board.size())continue;
        int cur = board[arr[moves[i]]][moves[i]];
        if (cur != 0)
        {
            if (s.empty())
                s.push(cur);
            else
            {
                if (s.top() == cur)
                {
                    s.pop();
                    answer += 2;
                    
                }
                else
                    s.push(cur);
            }
            arr[moves[i]]++;
        }
    }
    return answer;
}