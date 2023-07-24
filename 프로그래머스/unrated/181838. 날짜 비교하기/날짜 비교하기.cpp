#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d1, vector<int> d2) {
    int answer = 0;
    if(d1[0]>d2[0])return 0;
    else if(d1[0]<d2[0])return 1;
    else 
    {
        if(d1[1]>d2[1])return 0;
        else if(d1[1]<d2[1])return 1;
        else
        {
            if(d1[2]>=d2[2])return 0;
            else return 1;
        }
    }
    return answer;
}