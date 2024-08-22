#include <vector>

using namespace std;

int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};

bool CheckPos(int x,int y,int m,int n)
{
    if(x>=0 && x<m && y>=0 && y<n)
        return true;
    else return false;
}

void DFS(vector<vector<int>>& board,
         vector<vector<bool>>& ch,int x,int y,int type,int& cnt,int m,int n)
{
    for(int i=0;i<4;i++)
    {
        if(CheckPos(x+dx[i],y+dy[i],m,n)&&ch[x+dx[i]][y+dy[i]]==false&&
          board[x+dx[i]][y+dy[i]]==type)
        {
            ch[x+dx[i]][y+dy[i]]=true;
            board[x+dx[i]][y+dy[i]]=0;
            DFS(board,ch,x+dx[i],y+dy[i],type,++cnt,m,n);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(picture[i][j]!=0)
            {
                vector<vector<bool>> ch(m,vector<bool>(n));
                int cnt=0;
                DFS(picture,ch,i,j,picture[i][j],cnt,m,n);
                number_of_area++;
                if(max_size_of_one_area<cnt)max_size_of_one_area=cnt;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}