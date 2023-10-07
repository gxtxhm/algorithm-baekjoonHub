#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int n = 0;
    int ori = x;
    while(x>0)
    {
        n+=x%10;
        x/=10;
    }
    if(ori%n==0)
        return true;
    else 
        return false;
}