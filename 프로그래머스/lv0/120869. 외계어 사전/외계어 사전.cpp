#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    
       for(int j=0;j<dic.size();j++)
       {
           int arr[27]={0,};
           for(int i=0;i<dic[j].length();i++)
           {
               arr[dic[j][i]-97]=1;
           }
           int cnt=0;
           for(int i=0;i<spell.size();i++)
           {
               if(arr[spell[i][0]-97]==1)
               {
                   cnt++;
               }
           }
           if(cnt==spell.size())return 1;
           
       }
    
    return 2;
}