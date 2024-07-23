#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id) {
    string answer = "";

    // 대문자를 소문자로 치환
    for (int i = 0; i < new_id.length(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            answer += new_id[i] + 32;
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9'))
            answer += new_id[i];
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            answer += new_id[i];
    }
    //3번
    int index = answer.find("..");
    while (index != string::npos)
    {
        answer = answer.replace(index, 2, ".");
        index = answer.find("..");
    }
    // 4번
    if (answer[0] == '.')
        answer.erase(0, 1);
    if (answer[answer.length()-1] == '.')
        answer.erase(answer.length()-1, 1);

    // 5번
    if (answer == "")
        answer += 'a';

    // 6번
    if (answer.length() >= 16)
        answer.erase(15);

    if (answer.back() == '.')
        answer.erase(answer.length() - 1, 1);

    // 7번
    if (answer.length() <= 2)
    {
        char c = answer.back();
        while (answer.length() <= 2)
        {
            answer += c;
        }
    }
    return answer;
}