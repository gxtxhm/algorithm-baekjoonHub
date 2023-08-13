#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    int im=0;
    
    for(int i=0;i<my_string.length();i++)
    {
        if(my_string[i]>='0'&&my_string[i]<='9')
        {
            if(im==0)im=(my_string[i]-'0');
            else 
            {
                im *= 10;
                im += my_string[i]-'0';
            }
            
        }
        else
        {
            answer+=im;
            im=0;
        }
    }
    if (im != 0)answer += im;
    return answer;
}