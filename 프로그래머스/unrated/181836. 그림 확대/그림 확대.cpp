#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for(int i=0;i<picture.size();i++)
    {
        string s="";
        for(int j=0;j<picture[i].length();j++)
        {
            for(int h=0;h<k;h++)
            {
                s+=picture[i][j];
            }
        }
        for(int h=0;h<k;h++)
        {
            answer.push_back(s);
        }
    }
    return answer;
}