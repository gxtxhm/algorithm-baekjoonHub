#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int n = 0;
    int pos = 0;

    int xCnt = 0, nCnt = 0;
    while ((n = polynomial.find(' ', pos)) != string::npos)
    {
        string a = polynomial.substr(pos, n - pos);
        if (a[a.length() - 1] == 'x')
        {
            if (a == "x")
                xCnt++;
            else
                xCnt += stoi(a.substr(0, a.length() - 1));
        }
        else
            nCnt += stoi(a);

        n += 3;
        pos = n;
    }
    string a = polynomial.substr(pos);
    if (a[a.length() - 1] == 'x')
    {
        if (a == "x")
            xCnt++;
        else
            xCnt += stoi(a.substr(0, a.length() - 1));
    }
    else
    {
        nCnt += stoi(a);
    }

    if (xCnt >= 1)
    {
        if(xCnt>1)
            answer = to_string(xCnt);
        answer += "x";
        if(nCnt!=0)
            answer += " + ";
    }
    
    if (nCnt != 0)
    {
        answer += to_string(nCnt);
    }
    
    return answer;
}