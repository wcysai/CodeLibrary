#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans[MAXN];
string str;
int mod1[MAXN],mod2[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=200000;i++)
    {
        int cnt=__builtin_popcount(i);
        ans[i]=ans[i%cnt]+1;
    }
    cin>>str;
    int cnt=0;
    for(int i=0;i<n;i++) if(str[i]=='1') cnt++;
    mod1[0]=1;
    for(int i=1;i<=200000;i++) mod1[i]=2LL*mod1[i-1]%(cnt+1);
    if(cnt>1)
    {
        mod2[0]=1;
        for(int i=1;i<=200000;i++) mod2[i]=2LL*mod2[i-1]%(cnt-1);
    }
    int res1=0,res2=0;
    for(int i=0;i<n;i++)
    {
        res1=(2LL*res1+(str[i]-'0'))%(cnt+1);
        if(cnt>1) res2=(2LL*res2+(str[i]-'0'))%(cnt-1);
    }
    for(int i=0;i<n;i++)
    {
        if(str[i]=='0')
        {
            int tmp=(res1+mod1[n-i-1])%(cnt+1);
            printf("%d\n",ans[tmp]+1);
        }
        else
        {
            if(cnt==1) puts("0");
            else
            {
                int tmp=(res2-mod2[n-i-1])%(cnt-1);
                if(tmp<0) tmp+=cnt-1;
                printf("%d\n",ans[tmp]+1);
            }
        }
        
    }
    return 0;
}