#include<bits/stdc++.h>
#define MAXN 100030
#define MOD 1000000007
using namespace std;
typedef pair<int,bool> P;
typedef long long ll;
char str[MAXN];
int cnt[26][MAXN],hbit[MAXN];
bool used[26];
int allo[26];
P check[26];
bool cmp(P x,P y)
{
    int a=x.first,b=y.first;
    if(!used[b]) return true;
    if(!used[a]) return false;
    else
    {
    int a1=hbit[a],a2=hbit[b];
    if(a1!=a2) return a1>a2;
    else
    {
    if(cnt[a][a1]!=cnt[b][a2]) return cnt[a][a1]>cnt[b][a2];
    else
    {
    while(a1>0&&a2>0)
    {
        a1--;
        a2--;
        if(cnt[a][a1]!=cnt[b][a2]) return cnt[a][a1]>cnt[b][a2];
    }
    return true;
    }
    }
    }
}
int n;
int main()
{
    int p=0;
    while(scanf("%d",&n)==1)
    {
    p++;
    int s=0;
    memset(cnt,0,sizeof(cnt));
    memset(hbit,0,sizeof(hbit));
    memset(allo,-1,sizeof(allo));
    memset(used,-1,sizeof(used));
    for(int i=0;i<26;i++)
    {
        check[i].first=i;
        check[i].second=true;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        int x=strlen(str);
        for(int j=0;j<x;j++)
        {
            if(!used[str[j]-'a']) s++;
            used[str[j]-'a']=true;
            cnt[str[j]-'a'][x-j-1]++;
            if(j==0&&x!=1) check[str[j]-'a'].second=false;
            hbit[str[j]-'a']=max(hbit[str[j]-'a'],x-j-1);
        }
    }
    for(int i=0;i<26;i++)
    {
        if(used[i])
        {
            for(int j=0;j<hbit[i];j++)
            {
                if(cnt[i][j]>=26)
                {
                    int x=cnt[i][j]/26;
                    cnt[i][j]-=x*26;
                    cnt[i][j+1]+=x;
                }
            }
            while(cnt[i][hbit[i]]>=26)
            {
                int x=cnt[i][hbit[i]]/26;
                cnt[i][hbit[i]]-=x*26;
                cnt[i][hbit[i]+1]+=x;
                hbit[i]++;
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        for(int j=i+1;j<26;j++)
        {
            if(!cmp(check[i],check[j]))
            {
                swap(check[i],check[j]);
            }
        }
    }
    if(s==26)
    {
        for(int i=25;i>=0;i--)
        {
            if(check[i].second)
            {
                allo[i]=0;
                break;
            }
        }
        int k=25;
        for(int i=0;i<26;i++)
        {
            if(allo[i]!=0)
            {
                allo[i]=k;
                k--;
            }
        }
    }
    else
    {
        int k=25;
        for(int i=0;i<s;i++)
        {
            allo[i]=k;
            k--;
        }
    }
    ll sum=0;
    for(int i=0;i<s;i++)
    {
        ll m=1;
        for(int j=0;j<=hbit[check[i].first];j++)
        {
            sum=(sum+allo[i]*cnt[check[i].first][j]*m)%MOD;
            m=m*26%MOD;
        }
    }
    printf("Case #%d: %I64d\n",p,sum);
    }
    return 0;
}
