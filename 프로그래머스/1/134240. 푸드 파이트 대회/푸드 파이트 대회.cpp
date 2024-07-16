#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    vector<int>a;
    vector<int>b;
    for(int i=1;i<food.size();i++)
    {
        if(food[i]>1)
        {
            a.push_back(food[i]/2);
            b.push_back(i);
        }
    }
    
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i];j++)
        {
            answer+=(b[i])+'0';
        }
    }
    answer+='0';
    for(int i=answer.length()-2;i>=0;i--)
        answer+=answer[i];
    return answer;
}