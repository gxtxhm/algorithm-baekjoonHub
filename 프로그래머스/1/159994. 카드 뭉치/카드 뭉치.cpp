#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int c1=0,c2=0;
    for(int i=0;i<goal.size();i++)
    {
        if(cards1[c1]==goal[i]||cards2[c2]==goal[i])
        {
            if(cards1[c1]==goal[i])
            {
                c1++;
            }
            else
                c2++;
        }
        else
        {
            return "No";
        }
    }
    
    return "Yes";
}