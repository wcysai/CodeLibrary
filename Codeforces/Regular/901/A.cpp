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
int t,n,m,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        multiset<int> sa,sb;
        ll suma=0,sumb=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            sa.insert(x); suma+=x;
        }
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            sb.insert(x); sumb+=x;
        }
        int last=-INF;
        for(int i=1;i<=k;i++){
            if(i&1){
                int y=*sa.begin(); int z=*(--sb.end());
                int delta=z-y;
                if(delta<0) delta=0;
                else{
                    sa.erase(sa.begin()); sb.erase(--sb.end());
                    sa.insert(z); sb.insert(y);
                }
                if(delta==last){
                    if((k-i)&1); else {suma+=delta; sumb-=delta;}
                    break;
                }
                suma+=delta; sumb-=delta;
                last=delta;
            }
            else{
                int y=*sb.begin(); int z=*(--sa.end());
                int delta=z-y;
                if(delta<0) delta=0;
                else{
                    sb.erase(sb.begin()); sa.erase(--sa.end());
                    sb.insert(z); sa.insert(y);
                }
                if(delta==last){
                    if((k-i)&1); else {sumb+=delta; suma-=delta;}
                    break;
                }
                sumb+=delta; suma-=delta;
                last=delta;
            }
        }
        printf("%lld\n",suma);
    }
    return 0;
}

