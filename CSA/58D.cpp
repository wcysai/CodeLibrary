#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
using namespace std;
int n,t;
int a[MAXN];
int bit[MAXN+1];
int save[20],st[20];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<(1<<n);i++)
            scanf("%d",&a[i]);
        for(int i=0;i<20;i++)
            save[i]=INF;
        save[0]=1;
        int base=1;
        for(int i=0;i<n;i++)
        {
            base*=2;
            for(int j=0;j<(1<<(n-i-1));j++)
            {
                a[j*base]=max(a[j*base],a[j*base+(base/2)]);
                save[i+1]=min(save[i+1],a[j*base]);
            }
        }
        st[0]=1;
        for(int i=0;i<n;i++)
            printf("%d\n",save[i]);
        for(int i=1;i<=n;i++)
            st[i]=max(1<<i,save[i-1]);
        st[n]=(1<<n);
        for(int i=0;i<n;i++)
            for(int j=st[i];j<st[i+1];j++)
                printf("%d ",i);
        printf("%d\n",n);
    }
    return 0;
}


