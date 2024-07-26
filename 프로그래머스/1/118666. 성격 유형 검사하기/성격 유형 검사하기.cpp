#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char,int> result; 
    result.insert({'R',0});
    result.insert({'T',0});
    result.insert({'C',0});
    result.insert({'F',0});
    result.insert({'J',0});
    result.insert({'M',0});
    result.insert({'A',0});
    result.insert({'N',0});
    
    
    for(int i=0;i<survey.size();i++)
    {
        // 비동의쪽 선택 , 1번유형
        if(choices[i]<=3)
        {
            result[survey[i][0]]+=4-choices[i];
        }
        // 동의쪽 선택, 2번유형
        else if(choices[i]>=5)
        {
            result[survey[i][1]]+=choices[i]-4;
        }
    }
    
    if(result['R']<result['T'])
        answer+="T";
    else 
        answer+="R";
    if(result['C']<result['F'])
        answer+='F';
    else
        answer+='C';
    if(result['J']<result['M'])
        answer+='M';
    else
        answer+='J';
    if(result['A']<result['N'])
        answer+='N';
    else
        answer+='A';
    
    
    return answer;
}