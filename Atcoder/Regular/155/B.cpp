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
int n,q,a,b;
set<int> s;
int main()
{
    scanf("%d%d%d",&q,&a,&b);
    s.insert(a-b); s.insert(a+b);
    for(int i=0;i<q;i++){
        int t;
        scanf("%d%d%d",&t,&a,&b);
        if(t==1) {s.insert(a-b); s.insert(a+b);}
        else{
            auto it=s.lower_bound(a);
            int ans;
            if(it==s.end()){
                ans=a-*(--it);
            }
            else{
                if(*it<=b) ans=0;
                else{
                    ans=*(it)-b;
                    if(it!=s.begin()) {it--; ans=min(ans,a-(*it));}
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

