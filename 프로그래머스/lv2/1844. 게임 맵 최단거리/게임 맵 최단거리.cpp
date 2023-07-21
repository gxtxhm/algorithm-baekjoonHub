#include<vector>
#include <iostream>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int sizeX = maps[0].size();
    int sizeY = maps.size();

    int answer = 0;
    int count[100][100] = { 0, };
    for (int i = 0; i < 100; i++)for (int j = 0; j < 100; j++)count[i][j] = -1;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    int curX = 0, curY = 0;
    count[0][0] = 1;
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();


        for (int i = 0; i < 4; i++)
        {
            int nextX = pos.first + dx[i];
            int nextY = pos.second + dy[i];

            if (0 <= nextX && nextX < sizeX && 0 <= nextY && nextY < sizeY && maps[nextY][nextX] == 1 && count[nextY][nextX] == -1)
            {
                count[nextY][nextX] = count[pos.second][pos.first] + 1;
                q.push(make_pair(nextX, nextY));
            }
        }
    }



    return count[sizeY - 1][sizeX - 1];
}