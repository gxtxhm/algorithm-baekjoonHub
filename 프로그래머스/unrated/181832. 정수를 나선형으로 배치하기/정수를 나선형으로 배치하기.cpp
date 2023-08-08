#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, -1));

    int dirX[4] = { 1,0,-1,0 };
    int dirY[4] = { 0,1,0,-1 };

    int dir = 0;

    int count = n;

    for (int i = 0; i < count; i++)
    {
        answer[0][i] = i + 1;
    }
    dir++;
    count--;

    int curX = n - 1, curY = 0;
    int cnt = n + 1;

    for (int k = count; k >= 0; k--)
    {
        for (int i = 0; i < k; i++)
        {
            curY += dirY[dir];
            curX += dirX[dir];
            answer[curY][curX] = cnt++;
        }
        dir = (dir + 1) % 4;
        for (int i = 0; i < k; i++)
        {
            curY += dirY[dir];
            curX += dirX[dir];
            answer[curY][curX] = cnt++;
        }
        dir = (dir + 1) % 4;
    }

    return answer;
}