#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char s[MAXN][MAXN],t[MAXN][MAXN],tmp[MAXN][MAXN];
void rotate()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            tmp[n+1-j][i]=s[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            s[i][j]=tmp[i][j];
}
void fit()
{
    int mini=INF,minj=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i][j]=='#') {mini=min(mini,i); minj=min(minj,j);}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i+mini-1<=n&&j+minj-1<=n) tmp[i][j]=s[i+mini-1][j+minj-1]; else tmp[i][j]='.';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            s[i][j]=tmp[i][j];
    mini=minj=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(t[i][j]=='#') {mini=min(mini,i); minj=min(minj,j);}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i+mini-1<=n&&j+minj-1<=n) tmp[i][j]=t[i+mini-1][j+minj-1]; else tmp[i][j]='.';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            t[i][j]=tmp[i][j];
}
bool check()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i][j]!=t[i][j]) return false;
    return true;
}
void print()
{
    for(int i=1;i<=n;i++)
        printf("%s\n",s[i]+1);
    puts("");
    for(int i=1;i<=n;i++)
        printf("%s\n",t[i]+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++) scanf("%s",t[i]+1);
    bool f=false;
    fit(); if(check()) f=true; 
    rotate(); fit(); if(check()) f=true;
    rotate(); fit(); if(check()) f=true;
    rotate(); fit(); if(check()) f=true;
    if(f) puts("Yes"); else puts("No");
    return 0;
}