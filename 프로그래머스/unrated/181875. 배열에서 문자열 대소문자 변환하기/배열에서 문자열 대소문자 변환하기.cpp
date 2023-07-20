#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for(int i=0;i<strArr.size();i++)
    {
        if(i%2==0){
            for(int j=0;j<strArr[i].length();j++){
                if(strArr[i][j]<97)strArr[i][j]+=32;
            }
        }
        else {
            for(int j=0;j<strArr[i].length();j++){
                if(strArr[i][j]>=97)strArr[i][j]-=32;
            }
        }
    }
    return strArr;
}