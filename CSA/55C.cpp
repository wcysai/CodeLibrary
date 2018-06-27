#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int n;
ll k;
int a[MAXN];
bool C(int x)
{
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=a[i]/x;
        if(cnt>=k) return true;
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    scanf("%I64d",&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int left=0,right=1e9+1;
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(C(mid)) left=mid; else right=mid;
    }
    printf("%d\n",left);
    return 0;
}

