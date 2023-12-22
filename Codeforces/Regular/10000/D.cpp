#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
char s[MAXN][MAXN];
int inv1[5*MAXN],inv2[5*MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=0;i<=5*n+1;i++) inv1[i]=inv2[i]=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            int cur=0;
            vector<int> tmp;
            for(int j=-n;j<=2*n;j++){
                cur^=inv1[i-j+2*n+1]; cur^=inv2[i+j+n];
                if(j>=1&&j<=n&&cur^(s[i][j]-'0')) 
                {
                    //printf("i=%d j=%d\n",i,j);
                    tmp.push_back(j); 
                }
            }
            ans+=(int)tmp.size();
            for(auto j:tmp){
                inv2[i+j+n]^=1;
                inv1[i-(j+1)+2*n+1]^=1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

