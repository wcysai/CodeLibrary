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
int t,n,k,a[MAXN],b[MAXN];
bool has[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n;i++) has[i]=false;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            has[a[i]]=true;
        }
        for(int i=0;i<=n;i++){
            if(!has[i]){
                a[0]=i;
                break;
            }
        }
        k%=(n+1);
        for(int i=1;i<=n;i++){
            int id=(i+n+1-k)%(n+1);
            b[i]=a[id];
        }
        for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
    }
    return 0;
}

