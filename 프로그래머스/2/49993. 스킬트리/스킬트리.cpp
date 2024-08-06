#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(auto& str : skill_trees)
    {
        vector<int> arr(26,0);
        for(int i=0;i<skill.length();i++)
            arr[skill[i]-65]=-1;

        int IdPointer=0;
        arr[skill[IdPointer]-65]=1;
        bool b=true;
        for(auto& c : str)
        {
            if(arr[c-65]==0||arr[c-65]==2)continue;
            else if(arr[c-65]==1)
            {
                arr[c-65]=2;
                IdPointer++;
                if(IdPointer<skill.length())
                    arr[skill[IdPointer]-65]=1;
            }
            else if(arr[c-65]==-1)
            {
                b=false;break;
            }
                
        }
        if(b)answer++;
    }
    
    return answer;
}