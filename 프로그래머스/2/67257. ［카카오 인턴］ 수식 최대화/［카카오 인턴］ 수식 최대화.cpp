#include <string>
#include <vector>
#include <stack>
#include <list>
#include <cctype>
using namespace std;

long long cal(long long a, long long b, char op)
{
    if (op == '*')
        return a * b;
    else if (op == '+')
        return a + b;
    else
        return a - b;
}

long long solution(string expression) {
    long long answer = 0;
    list<long long> l1;
    // * , + , - 기준
    vector<vector<char>>v1(6);
    v1[0] = { '*','+','-' };
    v1[1] = { '*','-','+' };
    v1[2] = { '+','*','-' };
    v1[3] = { '+','-','*' };
    v1[4] = { '-','*','+' };
    v1[5] = { '-','+','*' };
    string n = "";
    // 원본데이터
    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
            n += expression[i];
        else
        {
            l1.push_back(stoi(n)); n = "";
            l1.push_back((int)expression[i]);
        }
    }
    l1.push_back(stoi(n));
    long long max = -1;
    for (int i = 0; i < 6; i++)
    {
        list<long long> l2 = l1;
        for (int j = 0; j < 3; j++)
        {
            int idx = 0;
            for (list<long long>::iterator iter = l2.begin(); iter != l2.end();idx++)
            {
                if ((idx%2==1) && (char)(*iter) == v1[i][j])
                {
                    auto pre = prev(iter);
                    auto ne = next(iter);
                    *pre = cal(*pre, *ne, v1[i][j]);
                    iter = l2.erase(iter); iter = l2.erase(iter);
                    iter=pre;
                }
                else
                    iter++;
            }
            
        }
        if(l2.front()<0)l2.front()*=-1;
            if (max < l2.front())
                max = l2.front();
    }
    return max;
}