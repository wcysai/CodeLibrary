#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2048
#define MAXLOGN 11
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,K,a[MAXN];
int cnt[MAXN],curmax;
int s[MAXN][MAXN];
int bit[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    if(!i) return;
    while(i<2048)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int bisearch(int v)
{
    int sum=0,pos=0;
    for(int i=MAXLOGN;i>=0;i--)
    {
        if(pos+(1<<i)<2048&&sum+bit[pos+(1<<i)]<v)
        {
            sum+=bit[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos+1;
}
int dv(int a,int b) {return (a-1)/b+1;}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&K);
        for(int i=1;i<=N;i++) scanf("%d",&a[i]);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=2000;j++) s[i][j]=s[i-1][j];
            s[i][a[i]]++;
        }
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            int k=dv(K,dv(K,i));
            memset(bit,0,sizeof(bit));
            for(int j=1;j<=i;j++) add(a[j],1);
            for(int j=1;j+i-1<=N;j++)
            {
                int num=bisearch(k);
                int cnt=s[j+i-1][num]-s[j-1][num];
                if(s[j+i-1][cnt]-s[j-1][cnt]>0) ans++;
                add(a[j+i],1);
                add(a[j],-1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

