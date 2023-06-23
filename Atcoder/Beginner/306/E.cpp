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
int n,k,q;
int a[MAXN];
int state[MAXN];
multiset<int> s1;
multiset<int> s2;
int main()
{
    scanf("%d%d%d",&n,&k,&q);
    s1.insert(INF+1);
    for(int i=1;i<=k;i++) s1.insert(0);
    for(int i=1;i<=n-k;i++) s2.insert(0);
    ll ans=0;
    s2.insert(0);
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(s1.find(a[x])!=s1.end()){
            if((*(--s2.end()))>=y) {
                s1.erase(s1.find(a[x]));
                auto it=(--s2.end());
                ans+=*it; ans-=a[x];
                s1.insert(*it);
                s2.erase(it);
                s2.insert(y);
            }
            else{
                s1.erase(s1.find(a[x]));
                s1.insert(y);
                ans+=y; ans-=a[x];
            }
        }
        else{
            if(*(s1.begin())<=y){
                s2.erase(s2.find(a[x]));
                auto it=s1.begin();
                ans-=*it; ans+=y;
                s2.insert(*it);
                s1.erase(it);
                s1.insert(y);
            }
            else{
                s2.erase(s2.find(a[x]));
                s2.insert(y);
            }
        }
        a[x]=y;
        printf("%lld\n",ans);
    }
    return 0;
}

