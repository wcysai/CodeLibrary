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
int n,k,a[MAXN];
int b[MAXN];
int st[MAXN][20];
int pre[MAXN];
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=1;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<n;++j)
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int solve(int pos){
    if(pos+k-1>=n) return pos;
    
    if(query(pos,pos+k-1)!=a[pos]) return solve(pos+1);
    else{
        int now=1;
        for(int i=2;i<=k;i++){
            if(query(pos+i-1,pos+k-1)!=a[pos+i-1]) break;
            else now++;
        }
        if(now==k) return pos;
        else {
            int z=solve(pos+now);
            if(z==pos+now) return pos;
            else return z; 
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    init(n,a);
    int cnt=0;
    int pos=solve(1);
    sort(a+pos,a+pos+k);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

