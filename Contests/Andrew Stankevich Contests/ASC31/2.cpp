#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define BASE 19260817
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,h,a[MAXN],b[MAXN];
char str[MAXN][MAXN];
void go(int x,int y)
{
    str[x][y]='+';
    if(h==1) return;
    str[x+h-1][y]='+';
    for(int j=x+1;j<x+h-1;j++) str[j][y]='|';
}
void die()
{
    puts("inconsistent");
    exit(0);
}
bool cmp(int x,int y)
{
    return b[x]>b[y];
}
int main()
{
    scanf("%d%d%d",&n,&m,&h);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        a[i]=m-a[i];
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        sum+=b[i]*h;
    }
    if(sum!=n*m) die();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            str[i][j]='*';
    vector<int> v;
    for(int i=1;i<=m;i++) v.push_back(i);
    for(int i=1;i<=n-h+1;i++)
    {
        sort(v.begin(),v.end(),cmp);
        for(int _=0;_<m;_++)
        {
            int j=v[_];
            if(!a[i]) break;
            if(!b[j]) continue;
            if(str[i][j]!='*') continue;
            b[j]--;
            for(int k=i;k<=i+h-1;k++) a[k]--;
            go(i,j);
        }
    }
    for(int i=1;i<=n;i++) if(a[i]) die();
    for(int i=1;i<=m;i++) if(b[i]) die();
    for(int i=1;i<=n;i++) printf("%s\n",str[i]+1);
    return 0;
}
