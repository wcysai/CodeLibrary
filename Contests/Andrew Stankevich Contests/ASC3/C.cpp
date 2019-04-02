#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN];
set<int> changed;
void check(int x)
{
    bool f=false;
    int pos=x;
    while(pos>=0&&a[pos]!=2) 
    {
        if(a[pos]==0) f=true;
        pos--;
    }
    if(pos==-1) f=true;
    pos=x;
    while(pos<n&&a[pos]!=2)
    {
        if(a[pos]==0) f=true;
        pos++;
    }
    if(pos==n) f=true;
    if(!f)
    {
        assert(a[pos]==2);
        a[pos]=0; a[pos+1]++;
        changed.insert(pos); changed.insert(pos+1);
    }
}
bool checkleft(int x)
{
    if(x<0||x>=n) return false;
    bool f=false;
    int pos=x-1;
    while(pos>=0&&a[pos]!=2) 
    {
        if(a[pos]==0) f=true;
        pos--;
    }
    if(pos==-1) f=true;
    if(!f)
    {
        assert(a[pos]==2);
        a[x]=0; a[x+1]++;
        changed.insert(x); changed.insert(x+1);
        return true;
    }
    return false;
}
bool checkright(int x)
{
    if(x<0||x>=n) return false;
    bool f=false;
    int pos=x+1;
    while(pos<n&&a[pos]!=2) 
    {
        if(a[pos]==0) f=true;
        pos++;
    }
    if(pos==n) f=true;
    if(!f)
    {
        assert(a[pos]==2);
        a[pos]=0; a[pos+1]++;
        changed.insert(pos); changed.insert(pos+1);
        return true;
    }
    return false;
}
int main()
{
    freopen("counter.in","r",stdin);
    freopen("counter.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        changed.clear();
        int x;
        scanf("%d",&x);
        a[x]++; changed.insert(x);
        if(a[x]==1) check(x);
        else if(a[x]==2)
        {
            if(!checkleft(x)) checkright(x);
        }
        else
        {
            a[x]=1;
            a[x+1]++;
            changed.insert(x+1);
        }
        printf("%d ",(int)changed.size());
        for(auto x:changed) printf("%d %d ",x,a[x]);
        puts("");
    }
}
