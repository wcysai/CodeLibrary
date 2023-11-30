#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> a,b,c;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int t,x;
        scanf("%d%d",&t,&x);
        if(!t) a.push_back(x);
        else if(t==1) b.push_back(x);
        else c.push_back(x);
    }
    sort(b.begin(),b.end(),greater<int>());
    sort(c.begin(),c.end(),greater<int>());
    priority_queue<int,vector<int>,greater<int> > pque;
    ll ans=0,sum=0;
    for(auto x:a) {sum+=x; pque.push(x);}
    while(pque.size()>m) {sum-=pque.top(); pque.pop();}
    ans=max(ans,sum);
    int cur=0,num=0;
    for(int i=0;i<(int)c.size();i++){
        num+=c[i]; num=min(num,(int)b.size());
        while(cur<num){
            pque.push(b[cur]); sum+=b[cur]; cur++;
        }
        while(pque.size()>m-1-i) {sum-=pque.top(); pque.pop();}
        ans=max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}

