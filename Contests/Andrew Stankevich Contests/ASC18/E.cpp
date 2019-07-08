#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,now;
bool dead;
bool gone[MAXN];
int bit[2][MAXN];
void add(int id,int i,int v)
{
    while(i<MAXN)
    {
        bit[id][i]+=v;
        i+=i&-i;
    }
}
int bisearch(int id,int v)
{
    int sum=0,pos=0;
    for(int i=MAXLOGN-1;i>=0;i--)
    {
        if(pos+(1<<i)<MAXN&&sum+bit[id][pos+(1<<i)]<v)
        {
            sum+=bit[id][pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos+1;
}
int get_n_kth(int k)
{
    return bisearch(0,k);
}
int get_m_kth(int k)
{
    return bisearch(1,k);
}
void go()
{
    if(dead) 
    {
        now=(now+k-1)%(n+m);
        if(now+1<=n)
        {
            int id=get_n_kth(now+1);
            add(0,id,-1);n--;
        }
        else
        {
            int id=get_m_kth(now+1-n);
            add(1,id,-1);m--;
        }
    }
    else
    {
        now=(now+k-1)%(n+m+2);
        if(now==0) dead=true; 
        else if(now==n+1) {dead=true; now--;}
        else if(now<=n)
        {
            int id=get_n_kth(now);
            add(0,id,-1);n--;
        }
        else
        {
            int id=get_m_kth(now-n-1); 
            add(1,id,-1);m--;
        }
    }
}
int main()
{
    freopen("infinity.in","r",stdin);
    freopen("infinity.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) add(0,i,1);
    for(int i=1;i<=m;i++) add(1,i,1);
    int sum=n+m;
    now=0;
    for(int i=0;i<sum;i++) go();
    if(!dead) puts("0");
    else if(n==1) printf("%d\n",get_n_kth(1));
    else printf("-%d\n",get_m_kth(1));
    return 0;
}
