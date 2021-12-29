#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000
#define INV2 499122177
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k,n,m;
string str;
ll f[(1<<24)],g[(1<<24)];
int get_pos(int mask,int i)
{
    return (mask>>(2*i))&3;
}
int chg_pos(int mask,int i,int val)
{
    return mask^((val^get_pos(mask,i))<<(2*i));
}
void zeta(ll f[])
{
    for(int i=0;i<k;i++)
        for(int mask=0;mask<(1<<(2*k));mask++)
            if(get_pos(mask,i)==3) 
                for(int j=1;j<=3;j++) f[mask]+=f[mask^(j<<(2*i))];
}
void mobius(ll f[])
{
    for(int i=0;i<k;i++)
        for(int mask=0;mask<(1<<(2*k));mask++)
            if(get_pos(mask,i)==3) 
                for(int j=1;j<=3;j++) f[mask]-=f[mask^(j<<(2*i))];
}
void print(int mask)
{
    for(int i=k-1;i>=0;i--) printf("%d ",get_pos(mask,i));
    puts("");
    return;
}
map<char,int> mp;
//P:0 R:1 S:2
int main()
{
    mp['P']=0; mp['R']=1; mp['S']=2;
    scanf("%d%d%d",&k,&n,&m);
    for(int i=1;i<=n;i++) 
    {
        cin>>str;
        int now=1,mask=0;
        for(int j=0;j<k;j++)
            mask=mask*4+mp[str[j]];
        f[mask]++;
    }
    for(int i=1;i<=m;i++) 
    {
        cin>>str;
        int now=1,mask=0;
        for(int j=0;j<k;j++)
            mask=mask*4+mp[str[j]];
        g[mask]++;
    }
    zeta(f); zeta(g);
    for(int i=0;i<(1<<(2*k));i++) f[i]=f[i]*g[i];
    mobius(f);
    memset(g,0,sizeof(g));
    for(int i=0;i<(1<<(2*k));i++)
    {
        int mask=0;
        for(int j=k-1;j>=0;j--)
        {
            int id=get_pos(i,j);
            if(id!=3) id=(id+2)%3;
            mask=mask*4+id;
        }
        g[mask]=f[i];
    }
    for(int i=0;i<k;i++)
    {
        memset(f,0,sizeof(f));
        for(int j=0;j<(1<<(2*k));j++)
            for(int x=0;x<3;x++)
                if(get_pos(j,i)!=x) f[chg_pos(j,i,x)]+=g[j];
        swap(f,g);
    }
    for(int i=0;i<(1<<(2*k));i++)
    {
        bool f=true;
        for(int j=0;j<k;j++) if(get_pos(i,j)==3) f=false;
        if(f) printf("%lld\n",1LL*n*m-g[i]);
    }
    return 0;
}