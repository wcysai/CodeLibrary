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
int n,m,q,a[MAXN];
char s[MAXN];
int l[MAXN],r[MAXN];
int rk[MAXN];
vector<P> upd[MAXN];
int bit[2*MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s",s+1);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l[i],&r[i]);
        upd[l[i]].push_back(P(i,1));
        upd[r[i]+1].push_back(P(i,-1));
    }
    set<int> st;
    vector<P> v;
    int good=0;
    for(int i=1;i<=n;i++){
        for(auto p:upd[i]){
            if(p.S==1) st.insert(p.F);
            else st.erase(p.F);
        }
        int x=(!st.size()?m+1:*st.begin());
        if(x!=m+1) good++;
        v.push_back(P(x,i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<(int)v.size();i++) rk[v[i].S]=i+1;
    int cnt=0;
    for(int i=1;i<=n;i++) if(s[i]=='1') {cnt++; add(rk[i],1);}
    for(int i=0;i<q;i++){
        int x; scanf("%d",&x);
        if(s[x]=='1'){
            add(rk[x],-1); cnt--;
            s[x]='0';
        }
        else{
            add(rk[x],1); cnt++;
            s[x]='1';
        }
        printf("%d\n",min(cnt,good)-sum(min(cnt,good)));
    }
    return 0;
}

