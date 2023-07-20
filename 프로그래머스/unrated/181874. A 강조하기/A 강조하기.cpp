#include <string>
#include <vector>

using namespace std;

string solution(string m) {
    string answer = "";
    for(int i=0;i<m.length();i++)
    {
        if(m[i]==' ')continue;
        if(m[i]=='a')m[i]='A';
        else if(m[i]!='A'&&m[i]<97)m[i]+=32;
    }
    return m;
}