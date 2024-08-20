#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    string sa=to_string(a);
    string sb = to_string(b);
    return sa+sb > sb+sa;
}
string solution(vector<int> numbers) {
    string answer = "";
    stable_sort(numbers.begin(), numbers.end(), compare);

    int maxV=0;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if(maxV<numbers[i])maxV=numbers[i];
        answer += to_string(numbers[i]);
    }
    if(maxV==0)return "0";
    return answer;
}