#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int c=1;
    while(arr.size()>c)c*=2;
    
    while(arr.size()<c)
    {
        arr.push_back(0);
    }
    return arr;
}