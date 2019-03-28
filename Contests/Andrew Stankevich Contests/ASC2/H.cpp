#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 25
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,m;
int a[MAXN][MAXN];
int dummy[MAXN][MAXN];
int p2[MAXN*MAXN];
int perm[MAXN*MAXN];
bool vis[MAXN*MAXN];
const int base=1000000000;
const int base_digits=9;
struct bigint
{
    vector<int> a;
    int sign;
    int size()
    {
        if(a.empty()) return 0;
        int ans=(a.size()-1)*base_digits;
        int ca=a.back();
        while(ca) ans++,ca/=10;
        return ans;
    }
    bigint(int v) {*this=v;}
    void operator=(const bigint &v)
    {
        sign=v.sign;
        a=v.a;
    }
    void operator=(int v)
    {
        sign=1; a.clear();
        for(;v>0;v=v/base) a.push_back(v%base);
    }
    void trim()
    {
        while(!a.empty()&&!a.back()) a.pop_back();
        if(a.empty()) sign=1;
    }
    bigint operator+(const bigint &v) const
    {
        bigint res=v;
        for(int i=0,carry=0;i<(int)max(a.size(),v.a.size())||carry;++i)
        {
            if(i==(int)res.a.size()) res.a.push_back(0);
            res.a[i]+=carry+(i<(int)a.size()?a[i]:0);
            carry=res.a[i]>=base;
            if(carry) res.a[i]-=base;
        }
        return res;
    }
    void operator*=(int v)
    {
        if(v<0) sign=-sign,v=-v;
        for(int i=0,carry=0;i<(int)a.size()||carry;i++)
        {
            if(i==(int)a.size()) a.push_back(0);
            long long cur=a[i]*(long long)v+carry;
            carry=(int)(cur/base);
            a[i]=(int)(cur%base);
        }
        trim();
    }
    bigint operator*(int v) const
    {
        bigint res=*this;
        res*=v;
        return res;
    }
    void operator/=(int v)
    {
        if(v<0) sign=-sign,v=-v;
        for(int i=(int)a.size()-1,rem=0;i>=0;--i)
        {
            long long cur=a[i]+rem*(long long)base;
            a[i]=(int)(cur/v);
            rem=(int)(cur%v);
        }
        trim();
    }
    bigint operator/(int v) const
    {
        bigint res=*this;
        res/=v;
        return res;
    }
    friend ostream& operator<<(ostream &stream,const bigint &v)
    {
        stream<<(v.a.empty()?0:v.a.back());
        for(int i=(int)v.a.size()-2;i>=0;i--) 
            stream<<setw(base_digits)<<setfill('0')<<v.a[i];
        return stream;
    }
};
void make_indentity()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=(i-1)*m+j;
}
void reverse()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dummy[i][j]=a[n+1-i][m+1-j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=dummy[i][j];
}
void go(int x)
{
    vis[x]=true;
    if(!vis[perm[x]]) go(perm[x]);
}
bigint count()
{
    bigint ret=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            perm[(i-1)*m+j]=a[i][j];
    memset(vis,false,sizeof(vis));
    int cnt=0;
    for(int i=1;i<=n*m;i++) if(!vis[i]) {cnt++; go(i);}
    for(int i=0;i<cnt;i++) ret=ret*2;
    return ret;
}
void right_rotate()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dummy[i][j]=a[n+1-j][i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=dummy[i][j];
}
void right_shift()
{
    for(int i=1;i<=n;i++)
    {
        int t=a[i][m];
        for(int j=m;j>=2;j--) a[i][j]=a[i][j-1];
        a[i][1]=t;
    }
}
void down_shift()
{
    for(int i=1;i<=m;i++)
    {
        int t=a[n][i];
        for(int j=n;j>=2;j--) a[j][i]=a[j-1][i];
        a[1][i]=t;
    }
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
        puts("");
    }
}
int main()
{
    freopen("tickets.in","r",stdin);
    freopen("tickets.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n!=m)
    {
        if(n>m) swap(n,m);
        bigint ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<2;k++)
                {
                    make_indentity();
                    for(int turns=0;turns<i;turns++) down_shift();
                    for(int turns=0;turns<j;turns++) right_shift();
                    for(int turns=0;turns<k;turns++) reverse();
                    ans=ans+count();
                }
        ans=ans/(2*n*m);
        cout<<ans<<endl;
    }
    else
    {
        bigint ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<4;k++)
                {
                    make_indentity();
                    for(int turns=0;turns<i;turns++) down_shift();
                    for(int turns=0;turns<j;turns++) right_shift();
                    for(int turns=0;turns<k;turns++) right_rotate();
                    ans=ans+count();
                }
        ans=ans/(4*n*m);
        cout<<ans<<endl;
    }
    return 0;
}

