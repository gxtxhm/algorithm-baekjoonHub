#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mn;

vector<bool> Convert(int num)
{
    vector<bool> b;
    while (num > 0)
    {
        b.push_back(num % 2);
        num /= 2;
    }
    if (mn > b.size())
    {
        while (mn != b.size())
        {
            b.push_back(false);
        }
    }
    reverse(b.begin(), b.end());
    return b;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    mn = n;
    for (int i = 0; i < n; i++)
    {
        vector<bool> bit = Convert(arr1[i]);
        vector<bool> bit2 = Convert(arr2[i]);
        string s = "";
        for (int j = 0; j < n; j++)
        {
            if (bit[j] | bit2[j])
                s += '#';
            else
                s += ' ';
        }
        answer.push_back(s);
    }
    return answer;
}