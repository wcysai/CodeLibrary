#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
bool used[30];
int main()
{
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            used[a[i]+a[j]]=true;
    int cnt=0;
    for(int i=0;i<30;i++)
        if(used[i]) cnt++;
    printf("%d\n",cnt);
    return 0;
}
