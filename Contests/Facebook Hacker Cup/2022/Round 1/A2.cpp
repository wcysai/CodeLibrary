#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[2][MAXN];
int MOD[2]={1004535809,1000000009};
int BASE[2]={233,666};
P hsh[2][MAXN];
int pw[2][MAXN];
void init()
{
    for(int id=0;id<2;id++)
    {
        pw[id][0]=1;
        for(int i=1;i<=500000;i++) pw[id][i]=1LL*pw[id][i-1]*BASE[id]%MOD[id];
    }
}
void init_hsh(){
    for(int id=0;id<2;id++)
        for(int i=1;i<=n;i++)
        {
            hsh[id][i].F=(1LL*hsh[id][i-1].F*BASE[0]+a[id][i])%MOD[0];
            hsh[id][i].S=(1LL*hsh[id][i-1].S*BASE[1]+a[id][i])%MOD[1];
        }
}
P get_hash(int id,int l,int r)
{ 
    if(l>r) return P(0,0);
    int x=(hsh[id][r].F-1LL*hsh[id][l-1].F*pw[0][r-l+1]%MOD[0]);
    int y=(hsh[id][r].S-1LL*hsh[id][l-1].S*pw[1][r-l+1]%MOD[1]);
    if(x<0) x+=MOD[0]; if(y<0) y+=MOD[1];
    return P(x,y);
}
bool check(int l1,int r1,int l2,int r2)
{
    return (get_hash(0,l1,r1)==get_hash(1,l2,r2));
}
bool check_ans(int x,int y)
{
    if(x==0&&y!=0) return false;
    if(x==1&&y==0) return false;
    if(n==2&&((x&1)!=(y&1))) return false;
    return true;
}
int main()
{
    init();
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&k);
        for(int id=0;id<2;id++)
            for(int i=1;i<=n;i++) 
                scanf("%d",&a[id][i]);
        init_hsh();
        bool f=false;
        for(int i=0;i<=n-1;i++)
        {
            if(check(1,i,n-i+1,n)&&check(i+1,n,1,n-i))
            {
        //        printf("i=%d\n",i);
                if(check_ans(k,i)) {f=true; break;}
            }
        }
        printf("Case #%d: ",t);
        if(!f) puts("NO"); else puts("YES");
    }
    return 0;
}

