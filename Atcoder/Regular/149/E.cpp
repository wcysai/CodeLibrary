#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,b[MAXN],tmp[MAXN];
int fact[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int solve(vector<int>&L,vector<int> &R)
{
    /*for(auto x:L) printf("%d ",x);
    puts("");
    for(auto x:R) printf("%d ",x);
    puts("");*/
    for(int i=1;i<(int)L.size();i++) if(L[i]<L[i-1]) return 0;
    for(int i=0;i<(int)R.size();i++) if(R[i]>L[0]) return 0;
    int maxi=R[0],cnt=1;
    for(int i=1;i<(int)R.size();i++) 
    {
        if(R[i]>maxi) {cnt++; maxi=R[i];}
    }
    int l=(int)L.size(),r=(int)R.size();
    return 1LL*pow_mod(l+1,cnt)*fact[l]%MOD;
}
int main()
{
    fact[0]=1;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    int pos=k%n;
    for(int i=0;i<n;i++) tmp[i]=b[(i+pos)%n];
    swap(b,tmp);
    int l=m-1,r=n-l;
    if(k>=r)
    {
        vector<int> L,R;
        for(int i=0;i<l;i++) L.push_back(b[i]);
        for(int i=l;i<n;i++) R.push_back(b[i]);
        int x=k%r;
        rotate(R.rbegin(),R.rbegin()+x,R.rend());
        printf("%d\n",solve(L,R));
    }
    else
    {
        vector<int> L,R;
        for(int i=0;i<l;i++) L.push_back(b[i]);
        for(int i=n-k;i<n;i++) R.push_back(b[i]);
        printf("%d\n",solve(L,R));
    }
    return 0;
}

