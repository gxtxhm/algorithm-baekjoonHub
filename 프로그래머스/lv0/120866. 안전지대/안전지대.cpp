#include <string>
#include <vector>

using namespace std;

int posX[8]={1,1,1,0,-1,-1,-1,0};
int posY[8]={-1,0,1,1,1,0,-1,-1};

int solution(vector<vector<int>> board) {
    int n =board.size();
    int answer = n*n;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==1)
            {
                answer--;
                for(int k=0;k<8;k++)
                {
                    if(i+posY[k]>=0&&i+posY[k]<n&&j+posX[k]>=0&&j+posX[k]<n)
                    {
                        if(board[i+posY[k]][j+posX[k]]==0)
                        {
                            board[i+posY[k]][j+posX[k]]=2;answer--;
                        }   
                    }
                }
            }
        }
    }
    
    return answer;
}