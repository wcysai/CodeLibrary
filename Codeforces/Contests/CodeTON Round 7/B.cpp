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
int t,n,k;
char s[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt=0,l=n+1,r=0;
        for(int i=n;i>=1;i--) if(s[i]=='A') {cnt++; l=i;} else r=max(r,i);
        if(cnt==0||cnt==n) {printf("%d\n",0); continue;}
        printf("%d\n",max(0,r-l));
    }
    return 0;
}

