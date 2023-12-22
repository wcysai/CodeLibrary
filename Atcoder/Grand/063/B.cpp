#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int cnt[MAXN];
int match[MAXN],dp[MAXN];
vector<int> pos[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    vector<int> st;
    ll ans=0;
    for(int i=n;i>=1;i--){
        if(a[i]==1){
            int now=1;
            while(st.size()&&a[st.back()]==now+1){
                st.pop_back();
                now++;
            }
            if(!st.size()) ans+=(n-i+1);
            else ans+=st.back()-i;
        }
        else st.push_back(i);
    }
    printf("%lld\n",ans);
    return 0;
}

