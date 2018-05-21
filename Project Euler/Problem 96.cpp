#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<vector>
#include<assert.h>
#include<queue>
using namespace std;
int t;
int sudoku[10][10];
bool flag;
bool judge(int x,int y,int k)
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[x][i]==k) return false;
        if(sudoku[i][y]==k) return false;
    }
    int sx=(x/3)*3,sy=(y/3)*3;
    for(int i=sx;i<=sx+2;i++)
        for(int j=sy;j<=sy+2;j++)
            if(sudoku[i][j]==k) return false;
    return true;
}
void dfs(int num)
{
    if(num>80)
    {
        flag=true;
        return;
    }
    if(flag) return;
    int x=num/9,y=num%9;
    if(sudoku[x][y]!=0) dfs(num+1);
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(judge(x,y,i))
            {
                sudoku[x][y]=i;
                dfs(num+1);
                if(flag) return;
                sudoku[x][y]=0;
            }
        }
    }
    return;
}
int main()
{
	freopen("p096_sudoku.txt", "r", stdin);
    t=50;
    int ans=0;
    while(t--)
    {
        char str[100];
        gets(str);
        flag=false;
        memset(sudoku,0,sizeof(sudoku));
        char ch;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                scanf("%c",&ch);
                sudoku[i][j]=ch-'0';
            }
            getchar();
        }
        dfs(0);
        ans+=sudoku[0][0]*100+sudoku[0][1]*10+sudoku[0][2];
    }
    printf("%d\n",ans);
    fclose(stdin);
    return 0;
}
