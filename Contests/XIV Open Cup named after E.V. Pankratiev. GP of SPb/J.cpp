#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k;
int len[3];
P a[3][MAXN];
bool vis[30][30];
bool mark[30][30];
string str[3];
int main()
{
    freopen("snakes2.in","r",stdin);
    freopen("snakes2.out","w",stdout);
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&len[i]);
        for(int j=0;j<len[i];j++) scanf("%d%d",&a[i][j].F,&a[i][j].S);
    }
    for(int i=0;i<k;i++) str[i]="";
    memset(vis,false,sizeof(vis));
    memset(mark,false,sizeof(mark));
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<len[i];j++)
        {
            int x=a[i][j].F,y=a[i][j].S;
            if(vis[x][y]) mark[x][y]=true;
            else vis[x][y]=true;
        }
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<len[i];j++)
        {
            int x=a[i][j].F,y=a[i][j].S;
            if(mark[x][y])
            {
                if(vis[x][y]) str[i]+='-';
                else str[i]+='+',vis[x][y]=true;
            }
        }
    }
    for(int i=0;i<k;i++) cout<<str[i]<<endl;
    return 0;
}
