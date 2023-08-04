#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> a(51);
    
    for(int i=0;i<strArr.size();i++)
    {
        a[strArr[i].length()]++;
    }
    int answer=-1;
    for(int i=0;i<51;i++)
    {
        if(a[i]>answer)answer=a[i];
    }
    return answer;
}