#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[2*MAXN];
int bit[2*MAXN+1],ans[MAXN];
int sum(int i){
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=2*n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<pair<P,int> > v;
        for(int i=1;i<=2*n;i++) bit[i]=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]); 
            if(i<=a[i]) {v.push_back(make_pair(P(i,a[i]),a[i])); v.push_back(make_pair(P(n+i,n+a[i]),a[i]));}
            else v.push_back(make_pair(P(i,a[i]+n),a[i])); 
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(auto p:v){
            //printf("%d %d %d\n",p.F.F,p.F.S,p.S);
            ans[p.S]=p.F.S-p.F.F-sum(p.F.S);
            add(p.F.S,1);
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}

