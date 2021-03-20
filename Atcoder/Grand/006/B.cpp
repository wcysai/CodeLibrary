#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x;
int a[2*MAXN];
int main()
{
    scanf("%d%d",&n,&x);
    if(n==2)
    {
        if(x!=2) puts("No");
        else puts("Yes\n1\n3\n2");
        return 0;
    }
    if(x==1||x==2*n-1) puts("No");
    else if(x==2)
    {
        puts("Yes");
        a[n]=x;
        a[n-1]=x-1;
        a[n-2]=x+1;
        a[n+1]=x+2;
        int now=1;
        for(int i=1;i<=2*n-1;i++)
        {
            if(a[i]) continue;
            if(now==x-1) now=x+3;
            a[i]=now; 
            now++;
        }
        for(int i=1;i<=2*n-1;i++) printf("%d\n",a[i]);
    }
    else
    {
        puts("Yes");
        a[n]=x;
        a[n-1]=x+1;
        a[n-2]=x-1;
        a[n+1]=x-2;
        int now=1;
        for(int i=1;i<=2*n-1;i++)
        {
            if(a[i]) continue;
            if(now==x-2) now=x+2;
            a[i]=now; 
            now++;
        }
        for(int i=1;i<=2*n-1;i++) printf("%d\n",a[i]);
    }
    return 0;
}