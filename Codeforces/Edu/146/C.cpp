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
int t,n,s1,s2;
P r[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&s1,&s2);
        for(int i=1;i<=n;i++) {
            scanf("%d",&r[i].F);
            r[i].S=i;
        }
        sort(r+1,r+n+1,greater<P>());
        vector<P> v;
        for(int i=1;i<=n;i++){
            v.push_back(P(i*s1,0));
            v.push_back(P(i*s2,1));
        }
        sort(v.begin(),v.end());
        vector<int> v1,v2;
        int tot=0;
        for(int i=0;i<n;i++){
            if(v[i].S&1) v2.push_back(r[++tot].S); else v1.push_back(r[++tot].S);
        }
        printf("%d",(int)v1.size());
        for(auto x:v1) printf(" %d",x);
        printf("\n");
        printf("%d",(int)v2.size());
        for(auto x:v2) printf(" %d",x);
        printf("\n");
    }
    return 0;
}

