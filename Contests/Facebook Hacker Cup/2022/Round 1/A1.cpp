#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        int pos1=0,pos2=0;
        for(int i=0;i<n;i++) if(a[i]==1) pos1=i;
        for(int i=0;i<n;i++) if(b[i]==1) pos2=i;
        int d=(pos2-pos1+n)%n;
        bool f=true;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[(i+d)%n])
            {
                f=false;
                break;
            }
        }
        printf("Case #%d: ",t);
        if(!f) {puts("NO"); continue;}
        if(k==0&&d!=0) {puts("NO"); continue;}
        if(k==1&&d==0) {puts("NO"); continue;}
        if((n==2)&&((k&1)!=(d&1))) {puts("NO"); continue;}
        puts("YES");
    }
    return 0;
}

