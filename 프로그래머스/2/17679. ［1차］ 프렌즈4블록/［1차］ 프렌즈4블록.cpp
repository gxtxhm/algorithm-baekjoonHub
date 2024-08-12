#include <string>
#include <vector>

using namespace std;

bool cal(int& answer, vector<string>& board)
{
    vector<pair<int, int>> savePos;
    vector<string> chB;
    for (int i = 0; i < board.size(); i++)
    {
        string s = "";
        for (int j = 0; j < board[i].length(); j++)
        {
            s += (board[i][j] == ' ') ? '0' : '1';
        }
        chB.push_back(s);
    }
    for (int i = 0; i < board.size() - 1; i++)
    {
        for (int j = 0; j < board[i].size() - 1; j++)
        {
            if (board[i][j] == ' ')continue;
            if ((board[i][j] == board[i][j + 1]) && (board[i][j + 1] == board[i + 1][j]) &&
                (board[i + 1][j] == board[i + 1][j + 1]))
            {
                // 4개 일치
                for (int r = i; r <= i + 1; r++)
                    for (int c = j; c <= j + 1; c++)
                        if (chB[r][c] == '1') { answer++; chB[r][c] = '0'; }

                savePos.push_back({ i,j });
            }
        }
    }
    if (savePos.size() == 0)return false;

    for (auto item : savePos)
    {
        board[item.first][item.second] = ' ';
        board[item.first][item.second + 1] = ' ';
        board[item.first + 1][item.second] = ' ';
        board[item.first + 1][item.second + 1] = ' ';
    }

    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (cal(answer, board))
    {
        for (int i = 0; i < board[0].size(); i++)
        {
            for (int j = board.size()-1; j >=1 ; j--)
            {
                if (board[j][i] == ' ')
                {
                    int k = j-1;
                    while (k >= 1 && board[k][i] == ' ')
                        k--;
                    if (k == 0 && board[k][i] == ' ')
                        continue;
                    board[j][i] = board[k][i];
                    board[k][i] = ' ';
                }
            }

        }
    }

    return answer;
}