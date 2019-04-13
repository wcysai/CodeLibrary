#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 6005
#define INF 1000000000
#define MOD 1000000007
#define BASE 19260817
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,res;
char str[MAXN];
int p[MAXN];
int hsh[MAXN];
unordered_set<int> us[MAXN];
int main()
{
    freopen("dna.in","r",stdin);
    freopen("dna.out","w",stdout);
    p[0]=1;
    for(int i=1;i<=6000;i++) p[i]=1LL*BASE*p[i-1]%MOD;
    scanf("%s",str+1);
    n=strlen(str+1);
    hsh[0]=0;
    for(int i=1;i<=n;i++) hsh[i]=(1LL*hsh[i-1]*BASE+str[i])%MOD;
    int curans=0,curnum=0,res=0;
    for(int len=1;len<=n-1;len++)
    {
        int last=-1;
        for(int i=1;i+len<=n;i++)
        {
            int j=i+len;
            if(str[i]!=str[j])
            {
                if(last!=-1)
                {
                    int l=i-1-last+1;
                    int hash=(hsh[i-1]-1LL*hsh[last-1]*p[l])%MOD;
                    if(hash<0) hash+=MOD;
                    us[l].insert(hash);
                    last=-1;
                }
            }
            else if(last==-1) last=i;
        }
        if(last!=-1)
        {
            int l=n-len-last+1;
            int hash=(hsh[n-len]-1LL*hsh[last-1]*p[l])%MOD;
            if(hash<0) hash+=MOD;
            us[l].insert(hash);
            last=-1;
        }
    }
    for(int i=n;i>=1;i--)
    {
        res+=(int)us[i].size();
        if(us[i].size()) 
        {
            if(curans==0)
            {
                curans=i;
                curnum=(int)us[i].size();
            }
        }
    }
    printf("%d\n%d\n%d\n",res,curans,curnum);
    return 0;
}
