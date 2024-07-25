#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, float> a, pair<int, float> b)
{
    if (a.second > b.second)
        return true;
    else if (a.second < b.second)
        return false;
    else return a.first < b.first;

}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<float>arr(N + 1, 0);
    for (int i = 0; i < stages.size(); i++)
    {
        if (stages[i] == N + 1)continue;
        arr[stages[i]]++;
    }
    float n = stages.size();
    for (int i = 1; i < arr.size(); i++)
    {
        int s = arr[i];
        arr[i] /= n;
        n -= s;
    }
    vector<pair<int, float>> m;
    for (int i = 1; i < arr.size(); i++)
    {
        
        m.push_back(make_pair( i, arr[i]));
    }

    sort(m.begin(), m.end(), compare);

    for (auto& v : m)
        answer.push_back(v.first);

    return answer;
}