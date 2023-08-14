#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    
    reverse(bin1.begin(),bin1.end());
    reverse(bin2.begin(),bin2.end());
    int b1 = bin1.length();
    int b2 = bin2.length();
    int len = (b1 < b2)? b1 : b2;
    int i,ch=0;
    for(i=0;i<len;i++)
    {
        int t = (bin1[i]-'0') + (bin2[i]-'0');
        if(t==2)
        {
            if(ch==1)
            {
                answer = '1' + answer;
            }
            else
                answer = '0' + answer;
            ch=1;
        }
        else if(t==1)
        {
            if(ch==1)
            {
                answer = '0' + answer;
            }
            else
            {
                answer = '1' + answer;
                ch=0;
            }
        }
        else
        {
            if(ch==1)
            {
                answer = '1' + answer;
                ch=0;
            }
            else
            {
                answer = '0' + answer;
            }
        }
    }
    if(i==b1)
    {
        for(int j=i;j<b2;j++)
        {
            if(bin2[j]-'0'==0)
            {
                if(ch==1)
                {
                    answer = '1' + answer; 
                }
                else
                    answer = '0' + answer; 
                ch=0;
            }
            else
            {
                if(ch==1)
                {
                    answer = '0' + answer; 
                    ch=1;
                }
                else
                {
                    answer = '1' + answer; 
                    ch=0;
                }
                
            }
        }
    }
    if(i==b2)
    {
        for(int j=i;j<b1;j++)
        {
            if(bin1[j]-'0'==0)
            {
                if(ch==1)
                {
                    answer = '1' + answer; 
                }
                else
                    answer = '0' + answer; 
                ch=0;
            }
            else
            {
                if(ch==1)
                {
                    answer = '0' + answer; 
                    ch=1;
                }
                else
                {
                    answer = '1' + answer; 
                    ch=0;
                }
                
            }
        }
    }
    if(ch==1)
        answer = '1' + answer;
    return answer;
}