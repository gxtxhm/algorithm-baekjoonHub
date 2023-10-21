#include <string>
#include <vector>
#include<iostream>
using namespace std;

int answer = 0;
void recur(vector<int> number, int cnt, int num, int index)
{
    if (cnt!=3&&index >= number.size())return;
    if (cnt == 3)
    {
        //cout << "end : " << cnt << ' ' << num << ' ' << index<<endl;
        if (num == 0)
            answer++;
        return;
    }
    num += number[index];
    //cout <<"더함 : "<< cnt + 1 << ' ' << num << ' ' << index + 1 << endl;
    recur(number, cnt + 1, num, index + 1);
    num -= number[index];
    //cout << "더하지않음 : " << cnt<< ' ' << num << ' ' << index + 1 << endl;
    recur(number, cnt, num, index + 1);
}

int solution(vector<int> number) {
    recur(number, 0, 0, 0);
    return answer;
}