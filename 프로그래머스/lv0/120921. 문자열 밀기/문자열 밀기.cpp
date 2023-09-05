#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    
    for(answer=0;;answer++)
    {
        if(answer>A.length())return -1;
        if(A==B)
            break;
        char c = A[A.length()-1];
        for(int j=A.length()-1;j>=1;j--)
            A[j]=A[j-1];
        A[0]=c;
    }
    
    return answer;
}