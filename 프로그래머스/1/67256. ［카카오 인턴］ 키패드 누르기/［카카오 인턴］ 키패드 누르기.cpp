#include <string>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int posL=11,posR=12;
    
    map<int,pair<int,int>> m;
    m.insert({0,{3,1}});
    m.insert({11,{3,0}});
    m.insert({12,{3,2}});
    int num=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m.insert({++num,make_pair(i,j)});
    
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7)
        {
            posL=numbers[i];
            answer+="L";
        }
        else if(numbers[i]==3||numbers[i]==6||numbers[i]==9)
        {
            posR=numbers[i];
            answer+="R";
        }
        else
        {
            int a = abs(m[numbers[i]].first-m[posL].first) + 
                abs(m[numbers[i]].second-m[posL].second);
            int b = abs(m[numbers[i]].first-m[posR].first) + 
                abs(m[numbers[i]].second-m[posR].second);
            
            if(a<b)
            {
                answer+="L";
                posL = numbers[i];
            }
            else if(a==b)
            {
                if(hand=="left")
                {
                    answer+="L";
                    posL = numbers[i];
                }
                else
                {
                    answer+="R";
                    posR = numbers[i];
                }
            }
            else
            {
                answer+="R";
                posR = numbers[i];
            }
        }
    }
    
    return answer;
}