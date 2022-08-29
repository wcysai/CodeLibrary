#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,r,c;
string str[MAXN];
int cnt[MAXN][MAXN];
bool must[MAXN][MAXN];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++) cin>>str[i];
        bool f=true;
        memset(cnt,0,sizeof(cnt));
        memset(must,0,sizeof(must));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(str[i][j]=='^') must[i][j]=true;
                if(str[i][j]=='.') str[i][j]='^';
                if(str[i][j]=='^')
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k],ny=j+dy[k];
                        if(nx>=0&&nx<r&&ny>=0&&ny<c) cnt[nx][ny]++;
                    }
                }
            }
        queue<P> que;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(str[i][j]=='^'&&cnt[i][j]<2) que.push(P(i,j));
        while(que.size())
        {
            P p=que.front(); que.pop();
            int x=p.F,y=p.S;
            if(must[x][y]) {f=false; break;}
            str[x][y]='.';
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&nx<r&&ny>=0&&ny<c) 
                {
                    cnt[nx][ny]--;
                    if(cnt[nx][ny]==1&&str[nx][ny]=='^') que.push(P(nx,ny));
                }
            }
        }
        printf("Case #%d: ",t);
        if(f) 
        {
            puts("Possible");
            for(int i=0;i<r;i++) cout<<str[i]<<endl;
        }
        else puts("Impossible");
    }
    return 0;
}

