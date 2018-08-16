/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-16 16:24:55
 ************************************************************************/

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
const int maxn = 100500+5;
inline long long read()
{
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node
{
    int x,y,z;
}p[maxn];
int n,m;
map<int,int> H;
vector<int> Q;
void Li()
{
    for(int i=1;i<=n;i++)
        Q.push_back(p[i].z);
    sort(Q.begin(),Q.end());
    for(int i=1;i<=n;i++)
        p[i].z=lower_bound(Q.begin(),Q.end(),p[i].z)-Q.begin()+1;
}
bool cmpx(node A,node B)
{
    return A.x<B.x;
}
bool cmpy(node A,node B)
{
    return A.y<B.y;
}
int dp[maxn];
int d[maxn];
int A[MAXN],B[MAXN],C[MAXN],D[MAXN];
vector<int> occ[3][MAXN];
int lowbit(int x)
{
    return x&(-x);
}
void updata(int x,int val)
{
    for(int i=x;i<n+2;i+=lowbit(i))
        d[i]=max(d[i],val);
}
int query(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i))
        res=max(res,d[i]);
    return res;
}
void init(int x)
{
    for(int i=x;i<n+2;i+=lowbit(i))
        d[i]=0;
}
void solve(int L,int R){
    int m=(L+R)>>1;
    sort(p+L,p+m+1,cmpy);
    sort(p+m+1,p+R+1,cmpy);
    int j=L;
    for(int i=m+1;i<=R;i++){
        for(;j<=m&&p[j].y<p[i].y;j++)
            updata(p[j].z,dp[p[j].x]);
        int tmp=query(p[i].z-1)+1;
        dp[p[i].x]=max(dp[p[i].x],tmp);
    }
    for(int i=L;i<=m;i++)init(p[i].z);
    sort(p+m+1,p+R+1,cmpx);
}

void CDQ(int L,int R){
    if(L==R)return;
    int m=(L+R)>>1;
    CDQ(L,m);
    solve(L,R);
    CDQ(m+1,R);
}
struct nn{int x,y,z;};
vector<nn> save;
bool cmp(nn p, nn q)
{
    return p.x>q.x;
}
set<int> ss;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {occ[0][i].clear();occ[1][i].clear();occ[2][i].clear();}
    for(int i=1;i<=n;i++) {scanf("%d",&A[i]); occ[0][A[i]].push_back(i);}
    for(int i=1;i<=n;i++) {scanf("%d",&B[i]); occ[1][B[i]].push_back(i);}
    for(int i=1;i<=n;i++) {scanf("%d",&C[i]); occ[2][C[i]].push_back(i);}
    for(int i=1;i<=n;i++) scanf("%d",&D[i]);
        for(int i=1;i<=n;i++)
        {
            int v=D[i];
            for(int j=0;j<(int)occ[0][v].size();j++)
                for(int k=0;k<(int)occ[1][v].size();k++)
                    for(int l=0;l<(int)occ[2][v].size();l++)
                    {
                        nn newnode;
                        newnode.x=occ[0][v][j];
                        newnode.y=occ[1][v][k];
                        newnode.z=occ[2][v][l];
                        save.push_back(newnode);
                    }
        }
    for(int i=0;i<(int)save.size();i++)
        ss.insert(save[i].x);
    vector<int> vv(ss.begin(),ss.end());
    for(int i=1;i<=(int)save.size()+1;i++)
    {
        p[i].y=save[i-1].y,p[i].z=save[i-1].z;
        p[i].x=lower_bound(vv.begin(),vv.end(),save[i-1].x)-vv.begin();
        dp[i]=1;
    }
    Li();
    CDQ(1,n);
    int Ans = 0;
    for(int i=1;i<=n;i++)
        Ans=max(Ans,dp[i]);
    printf("%d\n",Ans);
}
