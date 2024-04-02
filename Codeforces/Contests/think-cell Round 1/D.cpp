#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
char str[MAXN];
ll ans[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",str+1);
        ans[n+1]=0;
        ll res=0;
        for(int i=n;i>=1;i--){
            if(str[i]=='0') ans[i]=ans[i+1];
            else{
                if(i==n) ans[i]=1;
                else if(i==n-1) ans[i]=2;
                else{
                    ans[i]=ans[i+3]+(n-i+1);
                }
            }
            res+=ans[i];
        }
        printf("%lld\n",res);
    }
    return 0;
}

