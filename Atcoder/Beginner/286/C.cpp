#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
char str[MAXN];
int calc(){
    int cnt=0;
    for(int i=1;2*i<=n;i++){
        if(str[i]!=str[n-i+1]) cnt++;
    }
    return cnt;
}
void shift(){
    char ch=str[1];
    for(int i=1;i<=n-1;i++) str[i]=str[i+1];
    str[n]=ch;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",str+1);
    ll ans=INF;
    for(int i=0;i<=n;i++){
        ans=min(ans,1LL*i*a+1LL*calc()*b);
        shift();
    }
    printf("%lld\n",ans);
    return 0;
}

