#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a,int b)
{
    if(a>b)
        return true;
    else return false;
}

string solution(string s) {
    sort(s.begin(),s.begin()+s.length(),compare);
    
    return s;
}