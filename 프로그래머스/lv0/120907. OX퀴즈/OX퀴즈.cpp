#include <string>
#include <vector>

using namespace std;

bool Cal(int n1, int n2, int ans, char op)
{
    switch (op)
    {
    case '+':
        return (n1 + n2 == ans) ? true : false;
    case '-':
        return (n1 - n2 == ans) ? true : false;
    case '*':
        return (n1 - n2 == ans) ? true : false;
    case '/':
        return (n1 - n2 == ans) ? true : false;
    }
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    for (int i = 0; i < quiz.size(); i++)
    {
        int pos = quiz[i].find(' ');
        string num1 = quiz[i].substr(0, pos);

        char op = quiz[i][pos + 1];

        int pos2 = quiz[i].find(' ', pos+3);
        string num2 = quiz[i].substr(pos + 3, pos2);

        string ans = quiz[i].substr(pos2 + 3);

        int n1 = stoi(num1);
        int n2 = stoi(num2);
        int an = stoi(ans);

        if (Cal(n1, n2, an, op))
            answer.push_back("O");
        else
            answer.push_back("X");
    }

    return answer;
}