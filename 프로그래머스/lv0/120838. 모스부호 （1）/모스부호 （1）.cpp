#include <string>
#include <vector>

using namespace std;

string solution(string letter) {
    string answer = "";
    string arr[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

    string im = "";
    for (int i = 0; i < letter.length(); i++)
    {
        if (letter[i] == ' ')
        {
            for (int j = 0; j < 26; j++)
            {
                if (im == arr[j])
                {
                    answer += ('a' + j);
                    im = "";
                }
                
            }
        }
        else
        {
            im += letter[i];
        }
    }
   for (int j = 0; j < 26; j++)
            {
                if (im == arr[j])
                {
                    answer += ('a' + j);
                    im = "";
                }
                
            }
    return answer;
}