#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[3][MAXN];
int lab[3][MAXN];
int cnt[3][21][MAXN];
int ans[MAXN];
int p[MAXN];
vector<int> dif;
mt19937 wcy(time(NULL));
bool check()
{
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        if(s.count(a[0][i]*441+a[1][i]*21+a[2][i])) return false;
        s.insert(a[0][i]*441+a[1][i]*21+a[2][i]);
    }
    return true;
}
vector<int> save[505];
void cons()
{
    for(int i=1;i<=n;i++)
        save[a[0][i]*21+a[1][i]].push_back(i);
    vector<int> order;
    for(int i=0;i<=500;i++)
        for(int j=0;j<=500;j++)
            if(save[j].size()) {order.push_back(save[j].back()); save[j].pop_back();}
    int now=1;
    for(int i=0;i<(int)dif.size();i++)
    {
        for(int j=now;j<=now+dif[i]-1;j++) {a[2][order[j-1]]=i; lab[2][order[j-1]]=dif[i];}
        now+=dif[i];
    }
}
void solve()
{
    for(int i=0;i<3;i++)
    {
        printf("%d\n",(int)dif.size());
        for(int j=1;j<=n;j++) printf("%d%c",a[i][j]+1,j==n?'\n':' ');
        fflush(stdout);
        for(int j=0;j<(int)dif.size();j++)
        {
            int sz;
            scanf("%d",&sz);
            for(int k=0;k<sz;k++)
            {
                int x;
                scanf("%d",&x);
                cnt[i][sz][x]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            bool f=true;
            for(int k=0;k<3;k++)
                if(!cnt[k][lab[k][i]][j]) f=false;
            if(f) ans[i]=j;
        }
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
}
int main()
{
    scanf("%d",&n);
    int rem=n;
    for(int i=20;i>=1;i--)
    {
        if(!rem) break;
        if(i!=1&&1LL*(i-1)*(i)/2>=rem) continue;
        dif.push_back(i);
        rem-=i;
    }
    int now=1;
    for(int i=0;i<(int)dif.size();i++)
    {
        for(int j=now;j<=now+dif[i]-1;j++) {a[0][j]=i; lab[0][j]=dif[i];}
        now+=dif[i];
    }
    now=1;
    for(int i=0;i<(int)dif.size();i++)
    {
        for(int j=now;j<=now+dif[i]-1;j++) {a[1][n+1-j]=i; lab[1][n+1-j]=dif[i];}
        now+=dif[i];
    }
    cons();
    while(!check())
    {
        now=1;
        for(int i=1;i<=n;i++) p[i]=i;
        shuffle(p+1,p+n+1,wcy);
        for(int i=0;i<(int)dif.size();i++)
        {
            for(int j=now;j<=now+dif[i]-1;j++) {int pos=p[j];  a[1][pos]=i; lab[1][pos]=dif[i];}
            now+=dif[i];
        }
        cons();
    }
    solve();
    return 0;
}

