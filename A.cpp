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
int t,n,q,a[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) cnt[i]=0; 
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); if(a[i]<=n) cnt[a[i]]++;}
        if(q>=n) {printf("%d\n",n); continue;}
        string ans="";
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=q) ans+='1';
            else
            {
                if(!cnt[q]||(n-i+1)<=q) {ans+='1'; q--; }
                else ans+='0';
            }
            if(a[i]<=n) cnt[a[i]]--;
        }
        cout<<ans<<endl;
    }
    return 0;
}

