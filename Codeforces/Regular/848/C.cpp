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
int t,n,k;
int id[26];
string a,b;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        set<char> s;
        cin>>a>>b;
        for(int i=0;i<n;i++) s.insert(a[i]);
        for(int i=0;i<26;i++) id[i]=0;
        int tot=0;
        for(auto ch:s) id[ch-'a']=++tot;
        ll ans=0;
        for(int i=0;i<(1<<tot);i++){
            int c=__builtin_popcount(i);
            if(c>k) continue;
            if(c<k&&(i!=(1<<tot)-1)) continue;
            ll res=0;
            int cnt=0;
            for(int j=0;j<n;j++){
                if(a[j]==b[j]||(id[a[j]-'a']&&(i&(1<<(id[a[j]-'a']-1))))) cnt++;
                else{
                    res+=1LL*cnt*(cnt+1)/2;
                    cnt=0;
                }
            }
            res+=1LL*cnt*(cnt+1)/2;
            ans=max(ans,res);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

