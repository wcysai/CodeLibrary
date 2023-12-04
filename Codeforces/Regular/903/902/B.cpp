#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> divi[MAXN];
set<P> s;
int p2[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    p2[0]=1;
    for(int i=1;i<=100000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); s.insert(P(a[i],i));}
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i) divi[j].push_back(i);
    int ans=0;
    while(s.size()){
        auto p=*(--s.end());
        int pos=p.S,val=p.F;
        int sz=(int)s.size(),cnt=0;
        for(auto x:divi[pos]){
            if(s.count(P(a[x],x))){
                cnt++;
                s.erase(P(a[x],x));
            }
        }
        add(ans,1LL*val*(p2[sz]-p2[sz-cnt]+MOD)%MOD);
    }
    printf("%d\n",ans);
    return 0;
}

