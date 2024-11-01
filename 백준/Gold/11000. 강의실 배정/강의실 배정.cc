#include<bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second < b.second)return false;
        else return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    vector<pair<int, int>> v(n);
    int maxTime = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (maxTime < v[i].second)maxTime = v[i].second;
    }
    sort(v.begin(), v.end());

    int time = 1;
    int maxx = 0;
    int idx = 0;
    while (time <= maxTime)
    {
        
        while (v[idx].first == time)
        {
            if (pq.empty())pq.push(v[idx]);
            else
            {
                if (pq.top().second > time)pq.push(v[idx]);
                else
                {
                    while (!pq.empty() && pq.top().second <= time)pq.pop();
                    pq.push(v[idx]);
                }
            }
            
            if (maxx < pq.size())maxx = pq.size();
            idx++; if (idx == n)break;
        }
        if (idx == n)break;
        time = v[idx].first;
    }
    cout << maxx;
    return 0;
}