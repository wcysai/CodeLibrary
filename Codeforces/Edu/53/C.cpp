/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 22:42:46
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y,a[MAXN];
int curx,cury;
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    scanf("%d%d",&x,&y);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='U') cury++;
        else if(str[i]=='D') cury--;
        else if(str[i]=='L') curx--;
        else curx++;
    }
    if(((x+y)&1)!=(n&1)||abs(x)+abs(y)>n) {puts("-1"); return 0;}
    x-=curx;y-=cury;
    for(int i=0;i<n;i++)
    {
        if(x<0&&str[i]=='R') a[i+1]=1;
        else if(x>0&&str[i]=='L') a[i+1]=1;
        else if(y<0&&str[i]=='U') a[i+1]=1;
        else if(y>0&&str[i]=='D') a[i+1]=1;
    }
    if(x==0&&y==0) {puts("0"); return 0;}
    assert((abs(x)+abs(y))%2==0);
    int need=(abs(x)+abs(y))/2;
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        int l=i-1,r=n;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(a[mid]-a[i-1]>=need) r=mid; else l=mid;
        }
        if(a[r]-a[i-1]>=need) ans=min(ans,r-i+1);
    }
    printf("%d\n",ans);
    return 0;
}

