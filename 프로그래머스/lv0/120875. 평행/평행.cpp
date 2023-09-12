#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    float a, b;

    a = (float)(dots[1][1] - dots[0][1]) / (dots[1][0] - dots[0][0]);
    b = (float)(dots[3][1] - dots[2][1]) / (dots[3][0] - dots[2][0]);
    if (a == b)return 1;

    a= (float)(dots[2][1] - dots[1][1]) / (dots[2][0] - dots[1][0]);
    b= (float)(dots[3][1] - dots[0][1]) / (dots[3][0] - dots[0][0]);
    if (a == b)return 1;

    a= (float)(dots[2][1] - dots[0][1]) / (dots[2][0] - dots[0][0]);
    b= (float)(dots[3][1] - dots[1][1]) / (dots[3][0] - dots[1][0]);
    if (a == b)return 1;
    
    return 0;
}