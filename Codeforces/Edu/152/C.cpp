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
int t,n,m;
char s[MAXN];
int nxtone[MAXN],prezero[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            prezero[i]=prezero[i-1];
            if(s[i]=='0') prezero[i]=i;
        }
        nxtone[n+1]=n+1;
        for(int i=n;i>=1;i--){
            nxtone[i]=nxtone[i+1];
            if(s[i]=='1') nxtone[i]=i;
        }
        set<P> s;
        for(int i=0;i<m;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            l=nxtone[l]; r=prezero[r];
            if(l>r){
                s.insert(P(-1,-1));
            }
            else s.insert(P(l,r));
        }
        printf("%d\n",(int)s.size());
    }
    return 0;
}

