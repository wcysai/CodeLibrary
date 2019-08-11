#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int N,L,M;
db logfact[MAXN];
db val[MAXN];
db basis=log(0.5);
const db eps=1e-10;
db logcomb(int n,int k)
{
    if(n<k) return 0.0;
    return logfact[n]-logfact[k]-logfact[n-k];
}
int main()
{
    freopen("intset.in","r",stdin);
    freopen("intset.out","w",stdout);
    logfact[0]=logfact[1]=0;
    for(int i=2;i<=1000000;i++) logfact[i]=logfact[i-1]+log(i);
    scanf("%d%d%d",&N,&L,&M);
    if(L>M) swap(L,M);
    db all=logcomb(N,L)+logcomb(N,M);
    for(int i=0;i<=L;i++)
    {
        if(L+M-i>N) val[i]=0;
        else val[i]=exp(logcomb(N,i)+logcomb(N-i,L-i)+logcomb(N-L,M-i)-all);
    }
    int id=-1;
    db ans=0.0;
    for(int i=0;i<=L;i++)
    {
        ans+=val[i];
        if(ans>0.5) {id=i; break;}
    }
    printf("%d\n",id);
    return 0;
}
