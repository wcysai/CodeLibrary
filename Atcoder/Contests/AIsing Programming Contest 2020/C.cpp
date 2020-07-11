#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int ans[MAXN];
int main()
{
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            for(int k=1;k<=100;k++)
            {
                int res=i*i+j*j+k*k+i*j+i*k+j*k;
                if(res<=10000) ans[res]++;
            }
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}