#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    int end,start,c;
    
    if(n==1)
    {
        start=0;end=slicer[1];c=1;
    }
    else if(n==2)
    {
        start=slicer[0];end=num_list.size()-1;c=1;
    }
    else if(n==3)
    {
        start=slicer[0];end=slicer[1];c=1;
    }
    else 
    {
        start=slicer[0];end=slicer[1];c=slicer[2];
    }
    
    for(int i=start;i<=end;i+=c)
    {
        answer.push_back(num_list[i]);
    }
    
    return answer;
}