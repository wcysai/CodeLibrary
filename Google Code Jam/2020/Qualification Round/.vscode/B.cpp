#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
char str[MAXN+1];
int num[MAXN];
int st[MAXN],ed[MAXN];
void solve(int l,int r)
{
    int mini=INF;
    for(int i=l;i<=r;i++) mini=min(mini,num[i]);
    st[l]+=mini; ed[r]+=mini;
    for(int i=l;i<=r;i++) num[i]-=mini;
    int last=l;
    for(int i=l;i<=r;i++)
    {
        if(num[i]==0)
        {
            if(last<i) solve(last,i-1);
            last=i+1;
        }
    }
    if(last<=r) solve(last,r);
}
int main()
{
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%s",str+1);
        n=strlen(str+1);
        for(int i=1;i<=n;i++) num[i]=str[i]-'0';
        for(int i=1;i<=n;i++) st[i]=ed[i]=0;
        solve(1,n);
        printf("Case #%d: ",_);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=st[i];j++) printf("(");
            printf("%c",str[i]);
            for(int j=1;j<=ed[i];j++) printf(")");
        }
        printf("\n");
    }
}