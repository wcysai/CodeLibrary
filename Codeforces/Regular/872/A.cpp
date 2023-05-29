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
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        set<int> s;
        int l=0,r=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]==-1) l++;
            else if(a[i]==-2) r++;
            else s.insert(a[i]);
        }
        if(!s.size()) {printf("%d\n",min(m,max(l,r))); continue;}
        s.insert(0); s.insert(m+1);
        int cnt=0,ans=0,sz=(int)s.size();
        for(auto x:s){
            ans=max(ans,sz+min(x-cnt,l)+min(m+1-x-(sz-1-cnt),r)-2);
            cnt++;
        }
        ans=min(ans,m);
        printf("%d\n",ans);
    }
    return 0;
}

