#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,a[MAXN];
bool valid[MAXN];
int main()
{
    a[0]=a[1]=1;
    for(int i=2;i<=1000;i++)
    {
        memset(valid,true,sizeof(valid));
        for(int k=1;2*k<=i;k++)
        {
            int x=2*a[i-k]-a[i-2*k];
            if(x>0&&x<=1000) valid[x]=false; 
        }
        int j=1;
        while(!valid[j]) j++;
        a[i]=j;
    }
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;
}