#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    vector<int>a;
    vector<int>b;
    
    for(int i=0;i<wallpaper.size();i++)
    {
        for(int j=0;j<wallpaper[0].length();j++)
        {
            if(wallpaper[i][j]=='#')
            {
                a.push_back(j);
                b.push_back(i);
            }
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    answer.push_back(b[0]);answer.push_back(a[0]);
    answer.push_back(b[b.size()-1]+1);answer.push_back(a[a.size()-1]+1);
    return answer;
}