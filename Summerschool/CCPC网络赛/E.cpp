#include<bits/stdc++.h>
#define MAXN 1000000005
using namespace std;
typedef long long ll;
ll f(int x)
{
    int p=x/4,q=x%4;
    ll s=2*p*p;
    if(q==1) s=s+(p-1);
    else if(q==2) s=s+2*p;
    else if(q==3) s=s+3*p;
    return s;
}
int n,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int left=3,right=100000;
        while(right-left>1)
        {
            int mid=(left+right)/2;
            if(f(mid)>=n) right=mid;
            else left=mid;
        }
        printf("%d\n",right);
    }
    return 0;
}

