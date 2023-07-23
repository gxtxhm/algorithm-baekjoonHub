#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int o=0,e=0;
    for(int i=0;i<num_list.size();i++)
    {
        if(i%2==0)o+=num_list[i];
        else e+=num_list[i];
    }
    if(e==o)return e;
    else return (e>o)?e:o;
    return answer;
}