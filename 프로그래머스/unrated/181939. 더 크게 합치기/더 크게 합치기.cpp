#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string s = to_string(a);
    string s2= to_string(b);
    return (s+s2>=s2+s)?stoi(s+s2):stoi(s2+s);
}