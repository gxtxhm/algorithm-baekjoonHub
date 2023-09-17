#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int coa = a;
    int cob = b;
    // 기약분수로 바꾸기
    for (int i = a; i >= 2; i--)
    {
        if (coa % i == 0 && cob % i == 0)
        {
            coa /= i;
            cob /= i;
        }
    }
    bool ansch = true;
    // 분모의 소인수찾기
    for (int i = 2; i <= cob; i++)//인수
    {
        bool ch = false;

        if (cob % i == 0)
        {
            for (int j = 2; j < i; j++)// 인수 중 소수인지?
            {
                if (i % j == 0)
                {
                    ch = true;
                    break;
                }
            }
            int arr[1001] = { 0, };
            // false면 소인수임
            if (ch == false)
            {
                if (i != 2 && i != 5)
                    ansch = false;

            }
        }
    }
    if (ansch == true)return 1;
    else return 2;
}