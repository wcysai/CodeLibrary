#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define BASE1 19260817
#define BASE2 19991020
#define MOD1 1000000007
#define MOD2 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[MAXN];
int n,t,last[MAXN];
P st[MAXN];
int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    scanf("%s",str+1);
    n=strlen(str+1);
    int ans=0,id=-1;
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='('||str[i]=='[')
        {
            int type=str[i]=='('?0:1;
            st[t++]=make_pair(i,type);
        }
        else 
        {
            int type=str[i]==')'?0:1;
            if(t>0&&st[t-1].S==type)
            {
                last[i]=last[st[t-1].F-1]?last[st[t-1].F-1]:st[t-1].F;
                t--; 
            }
            else t=0;
        }
    }
    for(int i=1;i<=n;i++) if(last[i]&&i-last[i]+1>ans) {ans=i-last[i]+1; id=last[i];}
    if(id!=-1)
    {
        for(int i=id;i<=id+ans-1;i++) printf("%c",str[i]);
        return 0;
    }
}
