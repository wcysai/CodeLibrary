#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,q,k,a[MAXN];
char s[MAXN];
bool tog[MAXN];
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) tog[i]=false;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                tog[i]=true; cnt++;
                for(int j=i;j<=n;j+=i) s[j]='0'+'1'-s[j];
            }
        }
        scanf("%d",&q);
        ll ans=0;
        for(int i=1;i<=q;i++){
            int x; scanf("%d",&x);
            if(tog[x]) cnt--; else cnt++;
            tog[x]=!tog[x];
        }
        printf("Case #%d: %d\n",t,cnt);
    }
    return 0;
}

