#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
char str[MAXN];
int main(){
    scanf("%d%d%d",&n,&a,&b); a=min(a,2*b);
    scanf("%s",str+1);
    int l=0,r=0;
    for(int i=1;i<=2*n;i++) if(str[i]=='(') l++; else r++;
    ll ans=1LL*max(r-l,l-r)*b/2;
    if(l>r){
        int k=(l-r)/2;
        for(int i=2*n;i>=1;i--) if(k&&str[i]=='(') {str[i]=')'; k--;}
    }
    else{
        int k=(r-l)/2;
        for(int i=1;i<=2*n;i++) if(k&&str[i]==')') {str[i]='('; k--;}
    }
    int sum=0,res=0;
    for(int i=1;i<=2*n;i++){
        if(str[i]=='(') sum++; else sum--;
        res=min(res,sum);
    }
    //printf("res=%d\n",res);
    ans+=1LL*((-res+1)/2)*a;
    printf("%lld\n",ans);
    return 0;
}

