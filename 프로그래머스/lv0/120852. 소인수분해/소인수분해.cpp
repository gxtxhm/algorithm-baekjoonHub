#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    bool arr[10001]={0,};
    
    int num = n;
    
    while(true)
    {
        bool ch=false;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                n/=i;
                arr[i]=true;
                ch=true;
                break;
            }
        }    
        if(ch==false)
        {
            arr[n]=true;
            break;
        }
    }
    for(int i=2;i<=num;i++)
    {
        if(arr[i]==true)answer.push_back(i);
    }
    
    
    return answer;
}