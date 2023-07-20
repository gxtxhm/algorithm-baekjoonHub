#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    int end = my_string.length()-is_suffix.length();
    for(int i=0;i<is_suffix.length();i++)
    {
        if(my_string[end+i]!=is_suffix[i])return 0;
    }
    return 1;
}