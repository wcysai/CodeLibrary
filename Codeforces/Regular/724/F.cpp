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
int n,k,a[MAXN];
int sgs[MAXN],sgd[MAXN];
bool valid[MAXN];
int main()
{
    sgs[1]=1; sgd[1]=0;
    for(int i=2;i<=100;i++)
    {
        memset(valid,false,sizeof(valid));
        for(int j=0;j<=i-1;j++)
        {
            //placing same
            if(j!=0&&j!=-1) valid[sgs[j]^sgs[i-1-j]]=true;
            //placing different
            valid[sgd[j]^sgd[i-1-j]]=true;
        }
        for(int t=0;;t++) if(!valid[t]) {sgs[i]=t; break;}
        memset(valid,false,sizeof(valid));
        for(int j=0;j<=i-1;j++)
        {
            //placing A
            if(j!=0) valid[sgs[j]^sgd[i-1-j]]=true;
            //placing B
            if(j!=i-1) valid[sgd[j]^sgs[i-1-j]]=true;
        }
        for(int t=0;;t++) if(!valid[t]) {sgd[i]=t; break;}
    }
    for(int i=0;i<=100;i++) printf("i=%d sgs=%d sgd=%d\n",i,sgs[i],sgd[i]);
    return 0;
}

