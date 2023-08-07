#include <string>
#include <vector>

using namespace std;

vector<int> slice(int s, int e, vector<int>& ans)
{
    vector<int> a(e - s + 1);

    copy(ans.begin() + s, ans.begin() + e + 1, a.begin());
    return a;
}

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer = arr;

    for (int i = 0; i < query.size(); i++)
    {
        if (i % 2 == 0)
        {
            answer = slice(0, query[i], answer);
        }
        else
        {
            answer = slice(query[i], answer.size() - 1, answer);
        }
    }

    return answer;
}

int main()
{
    vector<int> r = { 0, 1, 2, 3, 4, 5 };
    vector<int> a = { 4, 1, 2 };
    solution(r,a);

    return 0;
}