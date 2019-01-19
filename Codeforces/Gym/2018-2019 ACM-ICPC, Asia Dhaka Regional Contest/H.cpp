#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 78294349
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,R,C,tot,t;
int num[205][205],dummy[205][205];
char str[205];
P pos1[40005],pos2[40005];
bool vis[40005];
int prime[40005];
bool is_prime[40005];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void to_up()
{
    vector<int> v[205];
    for(int i=1;i<=C;i++) v[i].clear();
    for(int i=1;i<=C;i++)
        for(int j=R;j>=1;j--)
            if(num[j][i]) v[i].push_back(num[j][i]);
    memset(num,0,sizeof(num));
    for(int i=1;i<=C;i++)
    {
        for(int j=1;j<=R;j++)
        {
            if(!v[i].size()) break;
            num[j][i]=v[i].back(); v[i].pop_back();
        }
    }
}
void to_down()
{
    vector<int> v[205];
    for(int i=1;i<=C;i++) v[i].clear();
    for(int i=1;i<=C;i++)
        for(int j=1;j<=R;j++)
            if(num[j][i]) v[i].push_back(num[j][i]);
    memset(num,0,sizeof(num));
    for(int i=1;i<=C;i++)
    {
        for(int j=R;j>=1;j--)
        {
            if(!v[i].size()) break;
            num[j][i]=v[i].back(); v[i].pop_back();
        }
    }
}
void to_left()
{
    vector<int> v[205];
    for(int i=1;i<=R;i++) v[i].clear();
    for(int i=1;i<=R;i++)
        for(int j=C;j>=1;j--)
            if(num[i][j]) v[i].push_back(num[i][j]);
    memset(num,0,sizeof(num));
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            if(!v[i].size()) break;
            num[i][j]=v[i].back(); v[i].pop_back();
        }
    }
}
void to_right()
{
    vector<int> v[205];
    for(int i=1;i<=R;i++) v[i].clear();
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(num[i][j]) v[i].push_back(num[i][j]);
    memset(num,0,sizeof(num));
    for(int i=1;i<=R;i++)
    {
        for(int j=C;j>=1;j--)
        {
            if(!v[i].size()) break;
            num[i][j]=v[i].back(); v[i].pop_back();
        }
    }
}
void print()
{
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
            printf("%d ",num[i][j]);
        puts("");
    }
}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int pw[40005];
int main()
{
    int p=sieve(40000);
    t=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&R,&C);
        memset(num,0,sizeof(num));
        memset(dummy,0,sizeof(dummy));
        memset(pw,0,sizeof(pw));
        tot=0;
        for(int i=1;i<=R;i++)
        {
            scanf("%s",str+1);
            for(int j=1;j<=C;j++) if(str[j]=='#') {num[i][j]=++tot; pos1[tot]=P(i,j); dummy[i][j]=num[i][j];}
        }
        to_up();to_right();to_down();to_left();
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                if(num[i][j]) pos2[num[i][j]]=P(i,j);
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=tot;i++)
        {
            if(!vis[i])
            {
                ll cnt=0,now=i;P pos=pos1[i]; 
                while(!vis[now])
                {
                    cnt++;
                    vis[now]=true;
                    pos=pos2[now];
                    now=dummy[pos.F][pos.S];
                }
                if(cnt>1)
                {
                    for(int j=0;j<p;j++)
                    {
                        if(cnt==1) break;
                        int res=0;
                        while(cnt%prime[j]==0) {cnt/=prime[j]; res++;}
                        if(res) pw[j]=max(pw[j],res);
                    }
                }
            }
        }
        int ans=1;
        for(int i=0;i<p;i++)
            if(pw[i])
                for(int j=0;j<pw[i];j++) ans=1LL*ans*prime[i]%MOD;
        printf("Case %d: %d\n",++t,ans);
    }
    return 0;
}

