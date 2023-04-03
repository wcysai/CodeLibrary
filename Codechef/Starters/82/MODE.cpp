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
int T,n,k,a[MAXN],ans[MAXN],num[MAXN],call[MAXN];
map<int,int> mp;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }
        for(int i=0;i<=n;i++) num[i]=call[i]=0;
        vector<int> v;
        for(auto p:mp) v.push_back(p.S);
        sort(v.begin(),v.end(),greater<int>());
        int cnt=1;
        for(int i=1;i<(int)v.size();i++) if(v[i]==v[0]) cnt++; else break;
        if(cnt==n){
            for(int i=1;i<=n/2;i++) ans[i]=i;
            for(int i=n/2+1;i<n;i++) ans[i]=-1;
            ans[n]=0;
            for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
            continue;
        }
        ans[n]=n-(int)v.size(); 
        for(int i=(n+1)/2;i<n;i++) ans[i]=-1;
        ans[cnt]=0;
        for(int i=1;i<cnt;i++) ans[i]=min(i,cnt-i);
        int sum=0;
        while(v.size()<n) v.push_back(0);
        for(int i=0;i<n;i++) call[v[i]]++;
        for(int i=1;i<=cnt;i++) {
            num[v[i-1]]++; call[v[i-1]]--;
            sum+=v[i-1];
        }
        for(int i=cnt+1;i<=n/2;i++){
            num[v[i-1]]++; call[v[i-1]]--; sum+=v[i-1];
            int less=0,cc=num[0];
            ans[i]=INF;
            for(int to=2;to*i<=n;to++){
                less+=num[to-1]*(to-1); cc+=num[to-1];
                int a=cc*to-less,b=sum-(num[to]*to+less)-(i-cc-num[to])*to,c=call[to];
                ans[i]=min(ans[i],max(a,b+c));
            }
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
        
    }
    return 0;
}

