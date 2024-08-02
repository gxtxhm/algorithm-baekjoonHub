#include <string>
#include <map>
using namespace std;

int Cnt=1;
bool find=false;
void recur(string curs,string destWord)
{
    if(find)return;
    if(curs.length()==5)return;
    char ch[]={'A','E','I','O','U'};
    for(int i=0;i<5;i++)
    {
        if(curs+ch[i]==destWord)
        {
            find=true;return;
        }
        if(!find)
            Cnt++;
        recur(curs+ch[i],destWord);
    }
}

int solution(string word) {
    int answer = 0;
  
    recur("",word);       
    
    return Cnt;
}