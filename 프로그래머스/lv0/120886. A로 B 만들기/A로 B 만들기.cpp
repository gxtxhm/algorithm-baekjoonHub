#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string before, string after) {
    int answer = 0;

    int arr[27] = { 0, };
    int arr2[27] = { 0, };
    for (int i = 0; i < after.length(); i++)
    {
        arr[before[i] - 97]++;
        arr2[after[i] - 97]++;
    }

    for (int i = 0; i < 27; i++)
    {
        if (arr[i] != arr2[i])return 0;
    }

    return 1;
}
