#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 1e9;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

bool Validation(int x, int y)
{
    if (x >= 0 && x <= 50*2 && y >= 0 && y <= 50*2)
        return true;
    else
        return false;
}

void dfs(vector<vector<int>>& board, int curX, int curY, int cnt)
{
    if (board[curX][curY] == 5)
    {
        if (cnt < answer)
            answer = cnt;

        return;
    }
    board[curX][curY] = 2;
    for (int i = 0; i < 4; i++)
    {
        int nx = curX + dx[i];
        int ny = curY + dy[i];
        // 유효한 좌표이며 굵은 선이면
        if (Validation(nx, ny) && 
            (board[nx][ny] == 1 || board[nx][ny] == 5))
        {
            dfs(board, nx, ny, cnt + 1);
        }
    }
    board[curX][curY] = 1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    vector<vector<int>> board(101, vector<int>(101,0));

    for (auto& item : rectangle)
    {
        // 직사각형의 선을 1로 채우기
        for (int i = item[0]*2; i <= item[2]*2; i++)
        {
            board[i][item[1]*2] = 1;
            board[i][item[3]*2] = 1;
        }
        for (int i = item[1]*2; i <= item[3]*2; i++)
        {
            board[item[0]*2][i] = 1;
            board[item[2]*2][i] = 1;
        }
    }
    for (auto& item : rectangle)
    {
        // 직사각형 안쪽을 2로 채우기
        for (int i = item[0]*2 + 1; i < item[2]*2; i++)
            for (int j = item[1]*2 + 1; j < item[3]*2; j++)
                board[i][j] = 2;
    }
    
    // 아이템 위치 표시
    board[itemX*2][itemY*2] = 5;
    dfs(board, characterX*2, characterY*2, 0);
    return answer/2;
}