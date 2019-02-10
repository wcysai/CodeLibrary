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
int n,tot;
char str[MAXN];
void add_edge(int u,int v)
{
    printf("%d %d\n",u,v);
}
void chrysanthemum(int v,int cnt)
{
    for(int i=1;i<cnt;i++)
    {
        ++tot;
        add_edge(v,tot);
    }
}
void solve()
{
    tot=0;
    int v=++tot,last=1;
    for(int i=2;i<=n;i++)
    {
        if(str[i]=='1')
        {
            add_edge(++tot,v);
            v=tot;
            chrysanthemum(v,i-last);
            last=i;
        }
    }
    add_edge(++tot,v);
    chrysanthemum(tot,n-last);
}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    if(str[n]=='1'||str[1]=='0')
    {
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(str[i]!=str[n-i])
        {
            puts("-1");
            return 0;
        }
    }
    solve();
    return 0;
}

