#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int n = stoi(to_string(a)+to_string(b));
    return (n>2*a*b)?n:2*a*b;
}