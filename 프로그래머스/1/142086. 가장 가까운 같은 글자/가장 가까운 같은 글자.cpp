#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int arr[27];
    for(int i=0;i<27;i++)
        arr[i]=-1;
    
    for(int i=0;i<s.length();i++)
    {
        
        if(arr[s[i]-'a']==-1)
        {
            answer.push_back(arr[s[i]-'a']);
            arr[s[i]-'a']=i;
        }
        else
        {
            answer.push_back(i-arr[s[i]-'a']);
            arr[s[i]-'a']= i;
        }
        
    }
    
    return answer;
}