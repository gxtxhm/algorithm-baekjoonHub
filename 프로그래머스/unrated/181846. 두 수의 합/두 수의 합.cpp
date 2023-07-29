#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

string solution(string a, string b) {
    string answer = "";
    int i;
    bool ch = false;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (i = 0; i < a.length() && i<b.length(); i++)
    {
        char num = ((a[i] - '0') + (b[i] - '0'))+'0';
        if (ch)num++;
        ch = false;
        if (num > 57)
        {
            ch = true;
            answer += ((num - '0') % 10+'0');
        }
        else answer += num;
    }
    // a가 안끝났으면
    while (i < a.length())
    {
        char num = a[i];
        if (ch)num++;
        ch = false;
        if (num > 57)
        {
            ch = true;
            answer += ((num - '0') % 10 + '0');
        }
        else answer += num;
        i++;
    }
    // b가 안끝났으면
    while (i < b.length())
    {
        char num = b[i];
        if (ch)num++;
        ch = false;
        if (num > 57)
        {
            ch = true;
            answer += ((num - '0') % 10 + '0');
        }
        else answer += num;
        i++;
    }
    if (ch)answer += 1+'0';
    reverse(answer.begin(), answer.end());
    return answer;
}