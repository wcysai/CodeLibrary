#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[4][MAXN];
vector<int> v[2];
int bit[2*MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        if(bit[i]&1) s^=1;
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n+1)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3;i++) 
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    bool f=true;
    int flip[2];
    flip[0]=flip[1]=0;
    for(int i=1;i<=n;i++)
    {
        int tmp[3];
        tmp[0]=a[1][i]; tmp[1]=a[2][i]; tmp[2]=a[3][i];
        sort(tmp,tmp+3);
        if(tmp[1]-tmp[0]!=1||tmp[2]-tmp[1]!=1) f=false;
        if(tmp[0]%3!=1) f=false;
        if(tmp[1]!=a[2][i]) f=false;
        if((i&1)==((tmp[0]/3)&1)) f=false;
        if(a[1][i]>a[3][i]) flip[(i&1)]^=1;
        v[(i&1)].push_back(tmp[0]/3);
    }
    int swp[2];
    swp[0]=swp[1]=0;
    memset(bit,0,sizeof(bit));
    for(auto x:v[0])
    {
        if(sum(n+1-x)&1) swp[0]^=1; 
        add(n+1-x,1);
    }
    memset(bit,0,sizeof(bit));
    for(auto x:v[1])
    {
        if(sum(n+1-x)&1) swp[1]^=1; 
        add(n+1-x,1);
    }
    if((flip[0]!=swp[1])||(flip[1]!=swp[0])) f=false;
    if(f) puts("Yes"); else puts("No");
    return 0;
}