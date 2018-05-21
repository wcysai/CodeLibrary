#include<bits/stdc++.h>
#define MAXN 1000000
using namespace std;
typedef long long ll;
int query;
ll p;
ll save[MAXN+3];
int main()
{
    for(ll i=1;i<=MAXN;i++)
        save[i]=i*i+(i+1)*(i+1)+i*(i+1);
    scanf("%d",&query);
    while(query--)
    {
        scanf("%lld",&p);
        int left=0,right=MAXN+1;
        bool f=false;
        while(right-left>1)
        {
            int mid=(left+right)/2;
            if(save[mid]>=p) right=mid; else left=mid;
            if(save[mid]==p)
            {
                f=true;
                printf("YES\n");
                break;
            }
        }
        if(!f) printf("NO\n");
    }
    return 0;
}
