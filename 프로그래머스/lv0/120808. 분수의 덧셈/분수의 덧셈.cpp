#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;

    // 분모 공배수 찾기
    int cnt1 = denom1, cnt2 = denom2;
    for (int i = 0; denom1 != denom2; i++)
    {
        if (denom1 < denom2)
            denom1 += cnt1;
        else
            denom2 += cnt2;
    }

    numer1 = (denom1 / cnt1) * numer1;
    numer2 = (denom2 / cnt2) * numer2;


    int numer = numer1 + numer2;
    int min = (numer> denom1) ? denom1 : numer;
    
        // 공약수가 있는가
        int i;
        for (i = min; i >= 2; i--)
        {
            //있으면 그 수로 나누기
            if (numer % i == 0 && denom1 % i == 0)
            {
                numer /= i;
                denom1 /= i;
            }
        }
        

        answer.push_back(numer);
        answer.push_back(denom1);
        
    

    return answer;
}