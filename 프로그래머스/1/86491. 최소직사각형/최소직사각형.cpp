#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w=1001,h=1001;
    for(int i=0;i<sizes.size();i++)
    {
        if(sizes[i][0]<sizes[i][1])
        {
            int k=sizes[i][0];
            sizes[i][0]=sizes[i][1];
            sizes[i][1]=k;
        }
    }
    w=sizes[0][0];
    h=sizes[0][1];
    for(int i=1;i<sizes.size();i++)
    {
        if(w<sizes[i][0])
            w=sizes[i][0];
        if(h<sizes[i][1])
            h=sizes[i][1];
    }
    return h*w;
}