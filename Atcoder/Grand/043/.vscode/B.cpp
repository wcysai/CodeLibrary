#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=1;i<=n;i++) a[i]=(str[i-1]-'0');
    for(int i=1;i<=n-1;i++) b[i]=max(a[i+1]-a[i],a[i]-a[i+1]);
    n--;
    int res=0;
    for(int i=0;i<=n-1;i++)
    {
        if(b[i+1]&1)
        {
            int x=1;
            for(int k=0;k<20;k++) if((!((n-1)&(1<<k)))&&(i&(1<<k))) x=0;
            res^=x;
        }
    }
    bool f=false;
    for(int i=1;i<=n;i++) if(b[i]==1) f=true;
    if(f)
    {
        printf("%d\n",res);
    }
    else 
    {
        for(int i=1;i<=n;i++) b[i]/=2;
        int res=0;
        for(int i=0;i<=n-1;i++)
        {
            if(b[i+1]&1)
            {
                int x=1;
                for(int k=0;k<20;k++) if((!((n-1)&(1<<k)))&&(i&(1<<k))) x=0;
                res^=x;
            }
        }
        printf("%d\n",res*2);
    }
    return 0;
}