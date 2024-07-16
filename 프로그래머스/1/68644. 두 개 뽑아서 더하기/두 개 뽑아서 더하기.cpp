#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int,bool> m;
    for(int i=0;i<numbers.size()-1;i++)
    {
        for(int j=i+1;j<numbers.size();j++)
        {
            if(m.find(numbers[i]+numbers[j])==m.end())
            {
                answer.push_back(numbers[i]+numbers[j]);
                m.insert({numbers[i]+numbers[j],true});
            }
        }
    }
    sort(answer.begin(),answer.begin()+answer.size());
    return answer;
}