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
int n,q,a[MAXN],b[MAXN],len[MAXN],cost[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    len[1]=1; cost[1]=0;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            len[i]=1; cost[i]=cost[i-1];
        }
        else{
            len[i]=len[i-1]+1; if(len[i]>=3) cost[i]=cost[i-1]+1;
            else cost[i]=cost[i-1];
        }
    }
    for(int i=0;i<q;i++){
        int l,r; scanf("%d%d",&l,&r);
        if(r-l+1<=2) printf("%d\n",r-l+1);
        else if(l==1) printf("%d\n",r-cost[r]);
        else if(len[r]>=r-l+1) printf("%d\n",2);
        else{
            int res=cost[r]-cost[l-1];
            if(len[l-1]==2){
                if(len[l+1]==4) res-=2;
                else if(len[l]==3) res--;
            }
            else if(len[l-1]==1){
                if(len[l+1]==3) res--;
            }
            else{
                if(len[l+1]==len[l-1]+2) res-=2;
                else if(len[l]==len[l-1]+1) res--;
            }
            printf("%d\n",r-l+1-res);
        }
    }
    return 0;
}

