#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    int cnt=0;
    while(t--)
    {
        cnt++;
        scanf("%d",&n);
        printf("Case #%d: %d\n",cnt,n/3);
    }
    return 0;
}
