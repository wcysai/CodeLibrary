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
int t,n,k,f[MAXN],d[MAXN],ans;
int cnt0[MAXN],cnt1[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&f[i]);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        ans=n;
        for(int i=1;i<=n;i++){
            ll lb=1LL*f[i]*d[i];
            int cnt=1; bool fl=true;
            vector<pair<ll,int> > v;
            for(int j=1;j<=n;j++){
                ll x=((lb-1)/f[j]+1);
                if(x>=1) v.push_back(make_pair(x*f[j],(x==d[j]?j:n+j)));  
                x--;
                if(x>=1) v.push_back(make_pair(x*f[j],(x==d[j]?j:n+j)));  
                x+=2;
                if(x>=1) v.push_back(make_pair(x*f[j],(x==d[j]?j:n+j)));  
            }
            sort(v.begin(),v.end());
            for(int j=1;j<=n;j++) cnt0[j]=cnt1[j]=0;
            int r=0,cc=0,call=0;
            for(int j=0;j<(int)v.size();j++){
                while(r<(int)v.size()&&v[r].F<=v[j].F+k) {
                    int num=(v[r].S>n?v[r].S-n:v[r].S);
                    if(cnt0[num]+cnt1[num]==0) call++;
                    if(v[r].S>n) cnt1[num]++; 
                    else {cnt0[num]++; cc++;}
                    r++;
                }
                if(call==n) ans=min(ans,n-cc);
                int num=(v[j].S>n?v[j].S-n:v[j].S);
                if(cnt0[num]+cnt1[num]==1) call--;
                if(v[j].S>n) cnt1[num]--;
                else {cnt0[num]--; cc--;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

