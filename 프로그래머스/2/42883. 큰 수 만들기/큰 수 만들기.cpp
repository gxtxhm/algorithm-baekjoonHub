#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int cnt=0;
    for(int i=0;i<number.length();i++)
    {
        while(!answer.empty() && answer.back() < number[i] && cnt < k)
        {
            answer.pop_back();cnt++;
        }
        answer.push_back(number[i]);
    }
    if(cnt!=k)
    {
        answer = answer.substr(0,answer.length()-(k-cnt));
    }
    return answer;
}