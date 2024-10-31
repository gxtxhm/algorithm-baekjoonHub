#include<bits/stdc++.h>
using namespace std;

void bfs(vector<pair<int, int>>& starts, vector<vector<int>>& g)
{
    vector<vector<int>> dist(g.size(), vector<int>(g[0].size(), 0));
    queue<pair<int, int>> q;

    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    for (int i = 0; i < starts.size(); i++)
    {
        int x, y; tie(x, y) = starts[i];
        q.push({ x,y });
        dist[x][y] = 1;
    }
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            if (g[i][j] == -1)dist[i][j] = -1;
        }
    }
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (nx >= 0 && nx < g.size() && ny >= 0 && ny < g[0].size() &&
                g[nx][ny] != -1 && dist[nx][ny] == 0)
            {
                q.push({ nx,ny });
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            if (dist[i][j] == 0)
            {
                cout << -1; return;
            }
            if (res < dist[i][j])res = dist[i][j];
        }
    }
    cout << res-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> m >> n;

    vector<vector<int>> g(n, vector<int>(m, 0));
    vector<pair<int, int>> starts;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> g[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 1)
            {
                starts.push_back({ i,j });
            }
        }
    }
    bfs(starts, g);
    return 0;
}