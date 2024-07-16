#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int wn;

bool compare(string a, string b)
{
    if(a[wn]==b[wn])return a<b;
    else if(a[wn]<b[wn])return true;
    else return false;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    wn=n;
    
    sort(strings.begin(),strings.begin()+strings.size(),compare);
    
    return strings;
}