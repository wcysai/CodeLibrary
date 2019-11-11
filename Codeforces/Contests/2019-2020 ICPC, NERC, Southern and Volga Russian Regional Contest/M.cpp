#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
vector<int> row[MAXN],col[MAXN];
bool check(int x,int suffix)
{
    if((x&suffix)!=suffix) return false;
    suffix=(suffix<<1)+1;
    if((x&suffix)==suffix) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;(1<<i)<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j&(1<<i)) row[tot].push_back(j);
            if((!(j&(1<<i)))&&(!((j+1)&(1<<i)))) col[tot].push_back(j);
        }
        if(row[tot].size()&&col[tot].size()) tot++; else {row[tot].clear(); col[tot].clear();}
    }
    for(int i=0;(1<<i)<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!(j&(1<<i))) row[tot].push_back(j);
            if(((j&(1<<i)))&&(((j+1)&(1<<i)))) col[tot].push_back(j);
        }
        if(row[tot].size()&&col[tot].size()) tot++; else {row[tot].clear(); col[tot].clear();}
    }
    for(int i=1;(1<<i)-1<=n;i++)
    {
        int suf=(1<<i)-1;
        for(int j=1;j<=n;j++)
        {
            if(check(j,suf)) col[tot].push_back(j);
            if(!check(j,suf)&&!check(j-1,suf)) row[tot].push_back(j);
        }
        if(row[tot].size()&&col[tot].size()) tot++; else {row[tot].clear(); col[tot].clear();}
    }
    printf("%d\n",tot);
    for(int i=0;i<tot;i++)
    {
        printf("%d ",(int)row[i].size());
        for(auto x:row[i]) printf("%d ",x);
        puts("");
        printf("%d ",(int)col[i].size());
        for(auto x:col[i]) printf("%d ",x);
        puts("");
    }
    return 0;
}
