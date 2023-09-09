#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Num;

bool compare(const int& a,const int& b)
{
    if(abs(Num-a)<abs(Num-b))
        return true;
    else if(abs(Num-a)==abs(Num-b))
    {
        if(a<b)
            return false;
        else return true;
    }
    else return false;
            
            
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    Num=n;
    sort(numlist.begin(),numlist.end(),compare);
    
    return numlist;
}