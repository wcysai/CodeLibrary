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
int t,n;
vector<int> v;
bool f;
int tot,tx,ty;
bool used[MAXN];
int ask(int x,int y)
{
    tot++; assert(tot<=2*n);
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int z; scanf("%d",&z);
    return z;
}
void answer(int x,int y)
{
    printf("! %d %d\n",x,y);
    fflush(stdout);
    int z;
    scanf("%d",&z);
}
void go()
{
    int x=v.back();
    int c=0;
    vector<int> tmp;
    int maxi=1;
    for(int i=0;i<(int)v.size()-1;i++)
    {
        int z=ask(x,v[i]);
        if(z==n-1) {tx=v.back(); ty=v[i]; f=true; return;}
        if(z>maxi)
        {
            tmp.clear();
            tmp.push_back(v[i]);
        }
        else if(z==maxi)
        {
            tmp.push_back(v[i]);
        }
    }
    if(tmp.size()==1) {tx=tmp[0]; ty=x; return;}
    assert(tmp.size()<v.size());
    swap(tmp,v);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) used[i]=false;
        if(n==2) {answer(1,2); continue;}
        int x=-1,y=-1,g=-1;
        for(int i=1;i<=n;i++) 
        {
            int nxt=(i==n?1:i+1);
            int gg=ask(i,nxt);
            if(gg!=1) {x=i; y=nxt; g=gg; break;}
        }
        used[x]=used[y]=true;
        for(int i=1;i<=n;i++)
        {
            if(used[i]) continue;
            used[i]=true;
            int z=ask(i,y);
            if(z==1) continue;
            else if(z==g) {y=i; g=ask(x,y); continue;}
            else if(z<g) continue;
            else {x=i; g=z;}
        }
        answer(x,y);
    }
    return 0;
}

