#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 195
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int s[MAXN];
int get_id(int i,int j)
{
    return s[i]+j;
}
int n,m;
char mp[MAXN][MAXN];
short toright[MAXN][MAXN],todown[MAXN][MAXN];
short row[22][MAXN][MAXN*MAXN/2],col[22][MAXN][MAXN*MAXN/2];
void update(short &a,short b) {a=max(a,b);}
int main()
{
    scanf("%d%d",&n,&m);
    s[1]=1;
    for(int i=2;i<=190;i++) s[i]=s[i-1]+(190-i+1);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++)
    {
        toright[i][m]=m;
        for(int j=m-1;j>=1;j--)
        {
            if(mp[i][j]==mp[i][j+1]) toright[i][j]=toright[i][j+1];
            else toright[i][j]=j;
        }
    }
    for(int i=1;i<=m;i++)
    {
        todown[n][i]=n;
        for(int j=n-1;j>=1;j--)
        {
            if(mp[j][i]==mp[j+1][i]) todown[j][i]=todown[j+1][i];
            else todown[j][i]=j;
        }
    }
    for(int i=0;i<=20;i++)
        for(int j=1;j<=m;j++)
            for(int l=1;l<=n;l++)
                for(int r=l;r<=n;r++)
                    row[i][j][get_id(l,r)]=-1;
    for(int i=0;i<=20;i++)
        for(int j=1;j<=n;j++)
            for(int l=1;l<=m;l++)
                for(int r=l;r<=m;r++)
                    col[i][j][get_id(l,r)]=-1;
    for(int pos=1;pos<=m;pos++)
    {
        for(int l=1;l<=n;l++)
        {
            row[0][pos][get_id(l,l)]=toright[l][pos];
            for(int r=l+1;r<=n;r++)
            {
                if(r>l&&mp[r-1][pos]!=mp[r][pos]) break;
                row[0][pos][get_id(l,r)]=min(row[0][pos][get_id(l,r-1)],toright[r][pos]);
            }
        }
    }
    for(int pos=1;pos<=n;pos++)
    {
        for(int l=1;l<=m;l++)
        {
            col[0][pos][get_id(l,l)]=todown[pos][l];
            for(int r=l+1;r<=m;r++)
            {
                if(r>l&&mp[pos][r-1]!=mp[pos][r]) break;
                col[0][pos][get_id(l,r)]=min(col[0][pos][get_id(l,r-1)],todown[pos][r]);
            }
        }
    }
    for(int turns=0;turns<=20;turns++)
    {
        if(row[turns][1][get_id(1,n)]==m)
        {
            printf("%d\n",turns);
            return 0;
        }
        for(int pos=1;pos<=m;pos++)
        {
            for(int l=1;l<=n;l++)
            {
                for(int r=l;r<=n;r++)
                {
                    if(row[turns][pos][get_id(l,r)]==-1) continue;
                    short val=row[turns][pos][get_id(l,r)];
                    short rightest=max(val,row[turns][val+1][get_id(l,r)]);
                    update(row[turns+1][pos][get_id(l,r)],rightest);
                    update(col[turns+1][l][get_id(pos,rightest)],r);
                }
            }
        }
        for(int pos=1;pos<=n;pos++)
        {
            for(int l=1;l<=m;l++)
            {
                for(int r=l;r<=m;r++)
                {
                    if(col[turns][pos][get_id(l,r)]==-1) continue;
                    short val=col[turns][pos][get_id(l,r)];
                    short downest=max(val,col[turns][val+1][get_id(l,r)]);
                    update(col[turns+1][pos][get_id(l,r)],downest);
                    update(row[turns+1][l][get_id(pos,downest)],r);
                }
            }
        }
    }
    return 0;
}

