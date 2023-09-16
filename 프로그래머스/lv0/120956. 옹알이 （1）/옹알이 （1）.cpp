#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
   
    for(int i=0;i<babbling.size();i++)
    {
        string a="";
        bool ch=false;
        
        for(int j=0;j<babbling[i].length();j++)
        {
            a+=babbling[i][j];
            if(a.length()==2)
            {
                if(a!="ye"&&a!="ma")
                {
                    ch=false;
                }
                else
                {
                    a="";
                    ch=true;
                }
            }
            if(a.length()==3)
            {
                if(a!="aya"&&a!="woo")
                {
                    ch=false;
                    break;
                }
                else
                {
                    ch=true;
                    a="";
                }
            }
        }
        if(a.length()!=0)
        {
            if(a=="aya"||a=="ye"||a=="woo"||a=="ma")
                ch=true;
            else
                ch=false;
        }
        
        if(ch==true)
            answer++;
    }
    
    return answer;
}