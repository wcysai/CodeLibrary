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
int t,n,k,a[MAXN];
string S,T;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>S>>T;
        int ans=INF,cnt=0;
        for(int i=0;i<n;i++) if(S[i]!=T[i]) cnt++;
        if(cnt==0) ans=0;
        else if(cnt&1) ans=min(ans,cnt*2-1); else ans=min(ans,cnt*2);
        cnt=0;
        for(int i=0;i<n;i++) if(S[i]!=T[n-1-i]) cnt++;
        if(cnt==0) ans=min(ans,2);
        else if(cnt&1) ans=min(ans,cnt*2); else ans=min(ans,cnt*2-1);
        printf("%d\n",ans);
    }
    return 0;
}

