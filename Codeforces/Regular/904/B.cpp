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
string str;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>str;
        for(int i=1;i<=n;i++) a[i]=str[i-1]-'0';
        set<int> pos0,pos1;
        for(int i=1;i<=n;i++) if(!a[i]) pos0.insert(n-i); else pos1.insert(n-i);
        if(!pos1.size()){
            for(int i=1;i<=n;i++) printf("%d%c",0,i==n?'\n':' ');
            continue;
        }
        ll ans=0;
        bool f=true;
        for(int i=1;i<=n;i++){
            while(pos0.size()&&(*pos0.begin()<i)) pos0.erase(pos0.begin());
            while(*pos1.begin()<i){
                if(!f) break;
                if(!pos0.size()) {f=false; break;}
                int x=*pos0.begin();
                ans+=x-(*pos1.begin());
                pos0.erase(pos0.begin());
                pos1.erase(pos1.begin());
                pos1.insert(x);
            }
            if(f) printf("%lld ",ans); else printf("-1 ");
        }
        printf("\n");
    }
    return 0;
}

