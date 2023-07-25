#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    string im="";
    for(int i=0;i<myStr.length();i++)
    {
        if(myStr[i]=='a'||myStr[i]=='b'||myStr[i]=='c')
        {
            if(im!="")answer.push_back(im);im="";
        }
        else
        {
            im+=myStr[i];
        }
    }
    if(im!="")answer.push_back(im);
    if(answer.size()==0)answer.push_back("EMPTY");
    return answer;
}