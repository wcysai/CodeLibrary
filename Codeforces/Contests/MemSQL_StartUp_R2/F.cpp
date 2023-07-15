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
int n,k,a[MAXN];
map<int,int> mp;
vector<P> v;
priority_queue<int,vector<int>,greater<int> > pque;
int main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x); mp[x]++;
        ans+=x;
    }
    for(auto p:mp) v.push_back(p);
    reverse(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<(int)v.size();i++){
        vector<int> tmp;
        int num=min(sum-2*(int)pque.size(),v[i].S);
        int rem=min(sum-num,v[i].S-num);
        for(int j=0;j<num;j++) tmp.push_back(v[i].F);
        for(int j=0;j<rem;j+=2){
            int x=pque.top(); pque.pop();
            if(x<v[i].F){
                tmp.push_back(v[i].F);
                if(j!=rem-1) tmp.push_back(v[i].F);
            }
            else{
                tmp.push_back(x);
                if(j!=rem-1&&2*v[i].F>x) tmp.push_back(2*v[i].F-x);
            }
        }
        for(auto x:tmp) pque.push(x);
        sum+=v[i].S;
    }
    while(pque.size()) {ans-=pque.top(); pque.pop();}
    printf("%lld\n",ans);
    return 0;
}

