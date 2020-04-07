#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n;
int a[MAXN];
bool st[MAXN];
int main()
{
    memset(st,false,sizeof(st));
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    if(n&1)
    {
        puts("(((");
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=2*n;i++)
    {
        if(st[a[i]])
        {
            continue;
        }
        else
        {
            st[a[i]]=true;
            cnt++;
            if(cnt==n/2) break;
        }
    }
    for(int i=1;i<=2*n;i++) if(st[a[i]]) printf("("); else printf(")");
    return 0;
}