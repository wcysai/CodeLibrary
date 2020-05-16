#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,a[MAXN],q,k,s;
int st[MAXN][20];
int pre[MAXN];
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
void update(int x)
{
    swap(a[x],a[x-1]);
    st[x-1][0]=a[x-1]; st[x][0]=a[x];
    for(int i=1;x-1+(1<<i)<n;i++)
    {
        if(min(st[x][i-1],st[x+(1<<i-1)][i-1])==st[x][i]) break;
        else st[x][i]=min(st[x][i-1],st[x+(1<<i-1)][i-1]);
    }
    for(int i=1;x>=(1<<i);i++)
    {
        if(min(st[x-(1<<i)][i-1],st[x-(1<<i)+(1<<i-1)][i-1])==st[x-(1<<i)][i]) break;
        else st[x-(1<<i)][i]=min(st[x-(1<<i)][i-1],st[x-(1<<i)+(1<<i-1)][i-1]);
    }
}
int query_mex(int l,int r)
{
    int ret=n;
    if(l) ret=min(ret,query(0,l-1));
    if(r<n-1) ret=min(ret,query(r+1,n-1));
    return ret;
}
int simulate()
{
    mt19937 gen;
    gen.seed(s);
    int last=0;
    while(q--)
    {
        int op=gen()%k;
        int i=(gen()+last)%n;
        if(!op&&i) 
        {
            update(i);
        }
        else
        {
            int j=gen()%n;
            if(i>j) swap(i,j);
            last^=query_mex(i,j);
        }
    }
    return last;
}
int main()
{
    freopen("J.in","r",stdin);
    scanf("%d%d%d%d",&n,&q,&k,&s);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    clock_t startTime,endTime;
    startTime = clock();
    init(n);
    printf("%d\n",simulate());
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}