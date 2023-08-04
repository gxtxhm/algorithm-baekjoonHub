#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for (int i = 0; i < 52; i++)answer.push_back(0);
    for (int i = 0; i < my_string.length(); i++)
    {
        if (my_string[i] > 96)
            answer[my_string[i] - 97 + 26]++;
        else
            answer[my_string[i] - 65]++;
    }
    return answer;
}