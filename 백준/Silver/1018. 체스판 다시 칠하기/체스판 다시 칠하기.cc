#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, m;
char board[50][50] = { 0, };
int calChangeBlock(int r, int c)
{
    int cnt = 0;
    char curChar = 'W';
    char curRowStartChar = curChar;
    for (int i = r; i < r + 8; i++)
    {
        curChar = curRowStartChar;
        curRowStartChar = (curRowStartChar == 'W') ? 'B' : 'W';
        for (int j = c; j < c + 8; j++)
        {
            if (board[i][j] != curChar) {
                cnt++;
            }
            if (curChar == 'W')curChar = 'B';
            else curChar = 'W';
        }
    }

    int cnt2 = 0;
    curChar = 'B';
    curRowStartChar = curChar;
    for (int i = r; i < r + 8; i++)
    {
        curChar = curRowStartChar;
        curRowStartChar = (curRowStartChar == 'W') ? 'B' : 'W';
        for (int j = c; j < c + 8; j++)
        {
            if (board[i][j] != curChar) {
                cnt2++;
            }
            if (curChar == 'W')curChar = 'B';
            else curChar = 'W';
        }
    }
    return (cnt < cnt2) ? cnt : cnt2;
}

int main()
{

    scanf("%d %d", &n, &m);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &board[i][j]);
        }
    }
    int minCnt = 2000000000;
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int cal = calChangeBlock(i, j);
            if (minCnt > cal)
                minCnt = cal;
        }
    }
    printf("%d", minCnt);

    return 0;
}