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
int t,n,k,c,a[MAXN];
ll calc(int x,int y){
    return max(1LL*y-x-c,1LL*c+x-y);
}
struct segtree{

}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&c);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(c>=0){
            sort(a+1,a+n+1);
            for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
            continue;
        }
        sort(a+1,a+n+1,greater<int>());
        a[0]=2*INF; a[n+1]=-INF;
        for(int i=2;i<=n-1;i++){
            int id=i;
            for(int j=i+1;j<=n;j++){
                ll x=calc(a[j-1],a[j])+calc(a[j],a[j+1])+calc(a[i-1],a[i])+(j==i+1?0:calc(a[i],a[i+1]));
                ll y=calc(a[i-1],a[j])+calc(a[j],a[i])+(j==i+1?calc(a[i],a[i+2]):calc(a[i],a[i+1]))+(j==i+1?0:calc(a[j-1],a[j+1]));
                if(x==y) id=j; 
            }
            if(id!=i){
                int tmp=a[id];
                for(int j=id-1;j>=i;j--) a[j+1]=a[j];
                a[i]=tmp;
            }
        }
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}

