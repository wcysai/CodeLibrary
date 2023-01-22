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
int t,n,m,a[MAXN];
vector<int> v;
int cnt[MAXN];
int res;
void add(int x,int v){
    for(int i=1;i*i<=x;i++){
        if(x%i) continue;
        if(i<=m) 
        {
            cnt[i]+=v; if(v==-1&&cnt[i]==0) res--; if(v==1&&cnt[i]==1) res++;
        }
        if(i*i!=x&&x/i<=m) 
        {
            cnt[x/i]+=v; if(v==-1&&cnt[x/i]==0) res--; if(v==1&&cnt[x/i]==1) res++;
        } 
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        v.clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            v.push_back(a[i]);
        }
        for(int i=1;i<=m;i++) cnt[i]=0;
        res=0;
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int l=0,r=0,ans=INF;
        for(;l<(int)v.size();){
            while(r<(int)v.size()&&res!=m) add(v[r++],1);
            if(res!=m) break;
            else{
                ans=min(ans,v[r-1]-v[l]);
            }
            add(v[l++],-1);
        }
        if(ans==INF) puts("-1"); else printf("%d\n",ans);
    }
    return 0;
}

