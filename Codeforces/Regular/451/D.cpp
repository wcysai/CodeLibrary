#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,m,k;
int a[MAXN];
bool used[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(n<k)
    {
        printf("0\n");
        return 0;
    }
    int s=0,t=k-1;
    int cnt=0;
    memset(used,false,sizeof(used));
    while(t<n)
    {
        while(a[t]-a[s]<m&&t<n)
        {
            used[t]=true;
            cnt++;
            t++;
        }
        if(t>=n) break;
        s++;
        while(used[s]) s++;
        t++;
    }
    printf("%d\n",cnt);
    return 0;
}

