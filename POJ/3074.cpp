#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<assert.h>
#include<map>
#include<queue>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
struct block
{
    bool used[10];
    int cnt;
    int num;
}sudoku[10][10];
bool row[10][10],col[10][10],sqr[10][10];
bool flag;
int program_counter;
char str[2000];
inline void update(int x,int y,int k)
{
    if(k!=0)
    {
        row[x][k]=true;
        col[y][k]=true;
        for(int i=0;i<9;i++)
        {
            if(!sudoku[x][i].used[k]) sudoku[x][i].cnt--;
            sudoku[x][i].used[k]=true;
        }
        for(int i=0;i<9;i++)
        {
            if(!sudoku[i][y].used[k]) sudoku[i][y].cnt--;
            sudoku[i][y].used[k]=true;
        }
        int sx=(x/3)*3,sy=(y/3)*3;
        sqr[sx*3+sy][k]=true;
        for(int i=sx;i<=sx+2;i++)
            for(int j=sy;j<=sy+2;j++)
            {
                if(!sudoku[i][j].used[k]) sudoku[i][j].cnt--;
                sudoku[i][j].used[k]=true;
            }
        sudoku[x][y].num=k;
    }
    else
    {
        k=sudoku[x][y].num;
        sudoku[x][y].num=0;
        row[x][k]=false;
        col[y][k]=false;
        int dx=(x/3)*3,dy=(y/3)*3;
        sqr[dx*3+dy][k]=false;
        for(int i=0;i<9;i++)
        {
            if(i==y) continue;
            if(sudoku[x][i].used[k])
            {
                int sx=(x/3)*3,sy=(i/3)*3,sqrnum=sx*3+sy;
                if(!col[i][k]&&!sqr[sqrnum][k])
                {
                    sudoku[x][i].cnt++;
                    sudoku[x][i].used[k]=false;
                }
            }
        }
        for(int i=0;i<9;i++)
        {
            if(i==x) continue;
            if(sudoku[i][y].used[k])
            {
                int sx=(i/3)*3,sy=(y/3)*3,sqrnum=sx*3+sy;
                if(!row[i][k]&&!sqr[sqrnum][k])
                {
                    sudoku[i][y].cnt++;
                    sudoku[i][y].used[k]=false;
                }
            }
        }
        for(int i=dx;i<=dx+2;i++)
            for(int j=dy;j<=dy+2;j++)
            {
                if(sudoku[i][j].used[k])
                {
                    if(!row[i][k]&&!col[j][k])
                    {
                        sudoku[i][j].cnt++;
                        sudoku[i][j].used[k]=false;
                    }
                }
            }
    }
}
inline void dfs()
{
    program_counter++;
    int t=10,tx=0,ty=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if((sudoku[i][j].num==0)&&(sudoku[i][j].cnt<=t))
            {
                t=sudoku[i][j].cnt;
                tx=i;
                ty=j;
            }
    if(t==10)
    {
        flag=true;
        return;
    }
    if(t==0)
    {
        return;
    }
    for(int i=1;i<=9;i++)
        if(!sudoku[tx][ty].used[i])
        {
            update(tx,ty,i);
            dfs();
            if(flag) return;
            update(tx,ty,0);
        }
    return;
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        if(str[0]=='e') return 0;
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(sqr,false,sizeof(sqr));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                for(int k=1;k<=9;k++)
                    sudoku[i][j].used[k]=false;
                sudoku[i][j].num=0;
                sudoku[i][j].cnt=9;
            }
        }
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                sudoku[i][j].num=str[i*9+j]=='.'?0:str[i*9+j]-'0';
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(sudoku[i][j].num>0) update(i,j,sudoku[i][j].num);
        flag=false;
        program_counter=0;
        dfs();
        printf("%d\n",program_counter);
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                printf("%d",sudoku[i][j].num);
        printf("\n");
    }
    return 0;
}
