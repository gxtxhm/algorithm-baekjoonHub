#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int e=0,o=0;
    for(int i=0;i<num_list.size();i++)
    {
        if(num_list[i]%2==0)
        {
            e*=10;e+=num_list[i];
        }
        else {
            o*=10;o+=num_list[i];
        }
    }
    return e+o;
}