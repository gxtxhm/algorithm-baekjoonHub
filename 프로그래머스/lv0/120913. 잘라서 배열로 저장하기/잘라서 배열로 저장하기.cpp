#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string im="";
    for(int i=0;i<my_str.length();i++)
    {
        if(i%n==0&&i/n>=1)
        {
            answer.push_back(im);
            im="";
        }
        im+=my_str[i];
    }
    answer.push_back(im);
    
        
    return answer;
}