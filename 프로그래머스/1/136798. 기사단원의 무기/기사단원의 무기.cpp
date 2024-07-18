#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=1;i<=number;i++)
    {
        // 약수 찾기
        int cnt=1;
        int im=i;
        int nC=2;
        int arr[100000]={0,};
        while(true)
        {
            if(im<=1)break;
            if(im%nC==0)
            {
                arr[nC]++;
                im/=nC;
            }
            else
                nC++;
        }
        for(int i=1;i<=nC;i++)
        {
            if(arr[i]!=0)
            {
                cnt*=(arr[i]+1);
            }
        }
        if(cnt>limit)
            cnt=power;
        answer+=cnt;
    }
    
    return answer;
}