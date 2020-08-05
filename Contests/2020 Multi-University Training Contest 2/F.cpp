#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define F first
#define S second
#define fmod adkfoas
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int MOD[5]={998244353,993244853,993244353,1000000007,1000000009};
int fmod[5][MAXN];
int n[3],a[3][MAXN],cnt[MAXN];
void add(int &a,int b,int m) {a+=b; if(a>=m) a-=m;}
void dec(int &a,int b,int m) {a-=b; if(a<0) a+=m;}
int T;
int main()
{
    for(int i=0;i<5;i++)
    {
        fmod[i][1]=1;
        fmod[i][2]=2;
        for(int j=3;j<=2000001;j++) 
        {
            fmod[i][j]=fmod[i][j-1];
            add(fmod[i][j],fmod[i][j-2],MOD[i]);
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<3;i++)
        {
            scanf("%d",&n[i]);
            for(int j=1;j<=n[i];j++) scanf("%d",&a[i][j]);
        }
        for(int i=1;i<=n[2];i++) cnt[i]=0;
        for(int i=0;i<5;i++)
        {
            int x=0,y=0;
            for(int j=1;j<=n[0];j++) if(a[0][j]) add(x,fmod[i][j],MOD[i]);
            for(int j=1;j<=n[1];j++) if(a[1][j]) add(y,fmod[i][j],MOD[i]);
            x=1LL*x*y%MOD[i];
            for(int j=1;j<=n[2];j++) if(a[2][j]) dec(x,fmod[i][j],MOD[i]);
            for(int j=1;j<=n[2];j++) if(!a[2][j]&&fmod[i][j]==x) cnt[j]++;
        }
        for(int i=1;i<=n[2];i++) if(cnt[i]==5) {printf("%d\n",i); break;}
    }
    return 0;
}