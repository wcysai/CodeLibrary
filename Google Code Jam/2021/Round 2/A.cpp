#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int query(int l,int r)
{
    printf("M %d %d\n",l,r);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void done()
{
    puts("D");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    assert(x==1);
}
void swap(int l,int r)
{
    if(l>r) swap(l,r);
    if(l==r) return;
    printf("S %d %d\n",l,r);
    fflush(stdout); 
    int x;
    scanf("%d",&x);
    assert(x==1);
}
int main()
{
    scanf("%d%d",&t,&n);
    for(int _=1;_<=t;_++)
    {
        for(int j=1;j<=n-1;j++)
        {
            int val=query(j,n);
            swap(j,val);
        }
        done();
    }
    return 0;
}