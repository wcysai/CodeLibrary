#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,p[MAXN],dp[MAXN][MAXN],a[MAXN],l[MAXN],r[MAXN],id[MAXN];
int x[MAXN],y[MAXN],z[MAXN];//[x,y) or [y,z)
vector<int> dis;
int st[MAXN][20],tmp[MAXN];
int pre[MAXN];
void prepare(int n){
    pre[1]=0;
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
}
void init(int n,int *arr){
    for(int i=n;i>=1;--i){
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r){
    if(l>r) return 0;
    int len=r-l+1,k=pre[len];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
bool cmp(int x,int y){
    return a[x]<a[y];
}
ll f[MAXN];
int ans[MAXN];
int main(){
    prepare(3000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d%d",&a[i],&l[i]); dis.push_back(a[i]); dis.push_back(a[i]+l[i]); dis.push_back(a[i]-l[i]);}
    for(int i=1;i<=n;i++) r[i]=i;
    sort(r+1,r+n+1,cmp);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    int sz=(int)dis.size();
    for(int i=1;i<=sz;i++) tmp[i]=-INF;
    for(int i=1;i<=n;i++){
        x[i]=lower_bound(dis.begin(),dis.end(),a[r[i]]-l[r[i]])-dis.begin()+1;
        y[i]=lower_bound(dis.begin(),dis.end(),a[r[i]])-dis.begin()+1;
        z[i]=lower_bound(dis.begin(),dis.end(),a[r[i]]+l[r[i]])-dis.begin()+1;
        id[y[i]]=i; tmp[y[i]]=z[i];
    }
    init(sz,tmp);
    for(int i=1;i<=sz;i++){
        for(int j=i;j<=sz;j++){
            dp[i][j]=dp[i][j-1]; 
            if(id[j]){
                //puts("here");
                //turn to right
                if(max(i,dp[i][j-1])>=y[id[j]]) dp[i][j]=max(dp[i][j],z[id[j]]);
                //turn to left
                //find first position k to "connect with" [x,y) (dp[pos]>=x[id[j]])
                int l=i-1,r=j;
                while(r-l>1){
                    int mid=(l+r)/2;
                    if(max(i,dp[i][mid])>=x[id[j]]) r=mid; else l=mid;
                }
                //turn all of [k,j-1] to right
                if(r<j){
                    int rb=max(max(j,dp[i][r]),query(r+1,j-1));
                    dp[i][j]=max(dp[i][j],rb);
                }
            }
        }
    }
    for(int i=1;i<=sz;i++){
        f[i]=f[i-1];
        for(int j=1;j<i;j++){
            if(dp[j][i]>=i) f[i]=max(f[i],f[j-1]+dis[i-1]-dis[j-1]);
        }
    }
    printf("%lld\n",f[sz]);
    return 0;
}

