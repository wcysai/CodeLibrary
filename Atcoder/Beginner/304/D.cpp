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
int w,h,n,p[MAXN],q[MAXN],A,B,a[MAXN],b[MAXN];
vector<int> add[MAXN];
map<int,int> mp;
int main()
{
    scanf("%d%d",&w,&h);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&q[i]);
    scanf("%d",&A);
    for(int i=1;i<=A;i++) scanf("%d",&a[i]);
    a[A+1]=w;
    scanf("%d",&B);
    for(int i=1;i<=B;i++) scanf("%d",&b[i]);
    b[B+1]=h;
    for(int i=1;i<=n;i++){
        p[i]=upper_bound(a+1,a+A+2,p[i])-a-1;
        q[i]=upper_bound(b+1,b+B+2,q[i])-b-1;
        add[p[i]].push_back(q[i]);
    }
    int maxi=-INF,mini=INF;
    for(int i=0;i<=A;i++){
        mp.clear();
        for(auto x:add[i]) mp[x]++;
        if(mp.size()<B+1) mini=0;
        for(auto p:mp){
            maxi=max(maxi,p.S);
            mini=min(mini,p.S);
        }
    }
    printf("%d %d\n",mini,maxi);
    return 0;
}

