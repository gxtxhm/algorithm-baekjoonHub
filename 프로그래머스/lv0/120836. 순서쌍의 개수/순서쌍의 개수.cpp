#include <string>

#include <string>
#include <vector>
#include<iostream>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    int i;
    for ( i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            answer++;
        }
    }
    return (n/sqrt(n) == i-1) ? answer * 2 - 1 : answer * 2;
}
