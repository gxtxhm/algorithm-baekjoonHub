#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    int in=0;
    int id;
    string a="";
    for(int i=0;i<my_string.length();i++)
    {
        if(my_string[i]==' ')
        {
            answer.push_back(a);
            a="";
        }
        else a+=my_string[i];
    }
    answer.push_back(a);
    return answer;
}