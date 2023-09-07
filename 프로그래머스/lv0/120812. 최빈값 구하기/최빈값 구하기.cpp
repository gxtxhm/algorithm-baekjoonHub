#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    map<int, int> m;

    if (array.size() == 1)
        return array[0];
    for (int i = 0; i < array.size(); i++)
    {
        if (m.find(array[i]) != m.end())
        {
            m[array[i]]++;
        }
        else
        {
            m.insert({ array[i],0 });

        }
    }
    int maxId = 0;
    bool ch = false;
    for (int i = 1; i < m.size(); i++)
    {
        if (m[i] > m[maxId])
        {

            maxId = i;
            ch = false;
        }
        else if (m[i] == m[maxId])ch = true;
    }
    if (ch)return -1;
    if (m.size() == 1)
        return m.find(array[0])->first;
    return maxId;
}