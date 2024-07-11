#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int a = (n>m)? m : n;
    
    for(int i=a; i>=1;i--)
    {
        if(n%i==0 && m%i==0)
        {
            answer.push_back(i); break;
        }
    }
    int oM=m;
    int oN=n;
    int nCnt=2;
    int mCnt=2;
    while(true)
    {
        if(n==m)
        {
            answer.push_back(n);break;
        }
        if(n>m)
        {
            m=oM;
            m*=mCnt;
            mCnt++;
        }
        else
        {
            n=oN;
            n*=nCnt;
            nCnt++;
        }
    }
    return answer;
}