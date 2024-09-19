#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    unordered_map<int, int>um;
    for (int i = 0; i < weights.size(); i++)
        um[weights[i]]++;

    for (pair<int, int> item : um)
    {
        int key = item.first;
        if (um[key] >= 2)
            answer+=((long long)item.second*(item.second-1)/2);
        
        if(key*2%1==0&&um.find(key*2) != um.end())
            answer+=(long long)um[key]*um[key*2];
        if(key*3%2==0&&um.find(key*3/2)!=um.end())
            answer+=(long long)um[key]*um[key*3/2];
        if(key*4%3==0&&um.find(key*4/3)!=um.end())
            answer+=(long long)um[key]*um[key*4/3];
    }
    return answer;
}