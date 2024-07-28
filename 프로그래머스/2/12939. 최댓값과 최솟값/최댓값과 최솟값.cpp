#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int max = -2147483648;
    int min = 2147483647 ;
    while(true)
    {
        int idx = s.find(' ');
        string im = s.substr(0,idx);
        int n = stoi(im);
        if(max<n)max=n;
        if(min>n)min=n;
        if(idx == string::npos)break;
        s=s.substr(idx+1);
    }
    answer=to_string(min)+" "+to_string(max);
    return answer;
}