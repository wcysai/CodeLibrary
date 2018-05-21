#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int l[MAXN],r[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&l[i],&r[i]);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j&&l[j]<l[i]&&r[j]>r[i])
            {
                cnt++;
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
