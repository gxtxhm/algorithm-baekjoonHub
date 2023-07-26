#include <string>
#include <vector>

using namespace std;

int minA = 2100000000;
string be;
string tar;
int check[51];

bool isChange(string word, string s)
{
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (word[i] == s[i])c++;
    }
    return (c + 1 == s.length()) ? true : false;
}

void D(vector<string> words, int cnt, int n, string cur)
{
    if (cur == tar)
    {
        if (cnt < minA)minA = cnt;
        return;
    }
    if (n == words.size())
    {
        if (cur == tar && cnt < minA)minA = cnt;
        return;
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (check[i] == 0 && isChange(words[i], cur))
        {
            check[i] = 1;

            D(words, cnt+1, n + 1,words[i]);

            check[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    be = begin;
    tar = target;
    D(words, 0, 0, begin);
    if (minA == 2100000000)return 0;
    return minA;
}