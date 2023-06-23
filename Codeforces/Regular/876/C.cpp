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
int t,n,k,a[MAXN],p[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(a[n]==1){
            puts("NO");
        }
        else{
            puts("YES");
            vector<int> v;
            for(int i=1;i<=n;i++) v.push_back(a[i]);
            int flip=0;
            while(v.size()>1){
                int sz=(int)v.size();
                if(v[sz-2]^flip){
                    p[sz]=sz-1;
                    v.pop_back(); flip^=1;
                }
                else{
                    p[sz]=sz-2;
                    v.pop_back(); v.pop_back(); v.push_back(0); flip^=1;
                }
            }
            p[0]=0;
            for(int i=1;i<=n;i++)printf("%d%c",p[i],i==n?'\n':' ');
        }
    }
    return 0;
}

