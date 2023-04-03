#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,a[MAXN],p[MAXN],val[MAXN];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) val[i]=i;
        for(int i=1;i<=n;i++) val[i]=val[p[i]];
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(val[i]);
        int val=-1,cnt=(int)s.size(),zeroes=0;
        for(int i=1;i<=n;i++) if(a[i]==0) zeroes++;
        for(auto x:s){
            if(a[x]!=0){
                cnt--;
                if(val==-1) val=a[x];
                else if(a[x]!=val) {val=-2; break;}
            }
            else zeroes--;
        }
        if(val==-2) {puts("0"); continue;}
        if(val!=-1||(!cnt)) printf("%d\n",pow_mod(m,zeroes));
        else printf("%d\n",pow_mod(m,zeroes+1));
    }
    return 0;
}

