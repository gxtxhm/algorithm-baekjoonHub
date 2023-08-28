#include <string>
#include <vector>
#include<cmath>
using namespace std;

int arr[31];
int arr2[31];
long long cal(int f, int b)
{
    int cnt = 0, cnt2 = 0;
    long long num = 1;
    for (int i = f; i <= b; i++)
        arr[cnt++] = i;

    for (int i = 1; i <= b-f+1; i++)
        arr2[cnt2++] = i;

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cnt2; j++)
        {
            if (arr2[j] != 0 && arr[i] % arr2[j] == 0)
            {
                arr[i] = arr[i] / arr2[j];
                arr2[j] = 0;
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        if (arr[i] != 0)num *= arr[i];
    }
    for (int i = 0; i < cnt2; i++)
    {
        if (arr2[i] != 0)num /= arr2[i];
    }
    return num;
}

long long solution(int balls, int share) {

    return cal(share + 1, balls);
}