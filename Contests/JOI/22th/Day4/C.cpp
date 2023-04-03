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
int n,q,x[MAXN],a[MAXN],b[MAXN],pre[MAXN];
int st[2][MAXN][20];
void init(int id,int n,int *arr){
    pre[1]=0;
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1];
        if((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=1;i--){
        st[id][i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[id][i][j]=max(st[id][i][j-1],st[id][i+(1<<j-1)][j-1]);
    }
}
int query(int id,int l,int r){
    if(l>r) return -INF;
    int len=r-l+1,k=pre[len];
    return max(st[id][l][k],st[id][r-(1<<k)+1][k]);
}
ll solve(int id){
    int l=id,r=id,pos=id;
    ll ans=0;
    while(l>1||r<n){
        if(l==1) return ans+x[n]-x[pos];
        if(r==n) return ans+x[pos]-x[1];
        if(x[pos]-x[l-1]<=x[r+1]-x[pos]){
            int lb=0,rb=l-1;
            while(rb-lb>1){
                int mid=(lb+rb)/2;
                if(query(0,mid,l-1)>x[r+1]) lb=mid; else rb=mid;
            }
            l=rb; ans+=x[pos]-x[rb]; pos=rb;
        }
        else{
            int lb=r,rb=n;
            while(rb-lb>1){
                int mid=(lb+rb)/2;
                if(query(1,r,mid)>=-x[l-1]) rb=mid; else lb=mid;
            }
            r=rb; ans+=x[rb]-x[pos]; pos=rb;
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        scanf("%d",&x[i]);
    for(int i=1;i<=n-1;i++){
        a[i]=2*x[i+1]-x[i];
        b[i]=x[i+1]-2*x[i];
    }
    init(0,n-1,a); init(1,n-1,b);
    scanf("%d",&q);
    while(q--){
        int pos;
        scanf("%d",&pos);
        if(pos>=x[n]) printf("%lld\n",pos-x[n]+solve(n));
        else{
            int id=lower_bound(x+1,x+n,pos)-x;
            if(id==1) printf("%lld\n",x[1]-pos+solve(1));
            else{
                if(pos-x[id-1]<=x[id]-pos) printf("%lld\n",pos-x[id-1]+solve(id-1));
                else printf("%lld\n",x[id]-pos+solve(id));
            }
        }
    }
    return 0;
}

