/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-14 18:08:33
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,r,c,x,y;
char mp[2005][2005];
int save[2005][2005];
struct node
{
    int xx,yy,num;
};
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&r,&c);r--;c--;
    scanf("%d%d",&x,&y);
    for(int i=0;i<n;i++) 
        scanf("%s",mp[i]); 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            save[i][j]=INF;
    deque<node> que;
    save[r][c]=0;
    que.push_back((node){r,c,0});
    while(que.size())
    {
        node p=que.front();que.pop_front();
        //printf("%d %d\n",p.xx,p.yy);
        if(p.num>save[p.xx][p.yy]) continue;
        int xx=p.xx,yy=p.yy;
        if(xx>0&&mp[xx-1][yy]!='*'&&save[xx-1][yy]>p.num)
        {
            save[xx-1][yy]=save[xx][yy];
            que.push_front((node){xx-1,yy,p.num});
        }
        if(xx<n&&mp[xx+1][yy]!='*'&&save[xx+1][yy]>p.num)
        {
            save[xx+1][yy]=save[xx][yy];
            que.push_back((node){xx+1,yy,p.num});
        }
        if(yy>0&&mp[xx][yy-1]!='*'&&save[xx][yy-1]>p.num&&p.num+1<=x)
        {
            save[xx][yy-1]=save[xx][yy]+1;
            que.push_front((node){xx,yy-1,p.num+1});
        }
        if(yy<m&&mp[xx][yy+1]!='*'&&save[xx][yy+1]>p.num&&p.num+1+(p.yy-c)<=y)
        {
            save[xx][yy+1]=save[xx][yy];
            que.push_front((node){xx,yy+1,p.num});
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(save[i][j]!=INF) ans++;
    printf("%d\n",ans);
    return 0;
}

