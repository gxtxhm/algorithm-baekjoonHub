#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    if(arr1.size()!=arr2.size()) return (arr1.size()>arr2.size())?1:-1;
    else {
        int s1=0,s2=0;
        for(int i=0;i<arr1.size();i++)s1+=arr1[i];
        for(int i=0;i<arr2.size();i++)s2+=arr2[i];
        if(s1==s2)return 0;
        else return (s1>s2)?1:-1;
    }
    return answer;
}