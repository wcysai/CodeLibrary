#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<P> v;
        for(int i=1;i<=n;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            v.push_back(P(r,l));
        }
        int cnt=0;
        while(v.size()>=2){
            sort(v.begin(),v.end());
            if(v[0].F<v[1].S){
                reverse(v.begin(),v.end());
                v.pop_back();
                continue;
            }
            int l=v[1].S,r=v[1].F;
            vector<P> tmp;
            for(auto p:v){
                if(p.S>r) tmp.push_back(p);
            }
            swap(v,tmp);
            cnt++;
        }
        printf("%d\n",n-2*cnt);
    }
    return 0;
}

