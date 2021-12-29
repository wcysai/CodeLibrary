#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char s[MAXN],t[MAXN];
vector<int> vs,vt;
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1); scanf("%s",t+1);
    if(n==0||m==0) {printf("%d\n",n+m-1); return 0;}
    for(int i=1;i<=n+m;i++)
    {
        if(s[i]=='0') vs.push_back(i);
        if(t[i]=='0') vt.push_back(i);
    }
    int ans=0;
    for(int x=0;x<2;x++)
        for(int y=0;y<2;y++)
        {
            int l=-INF,r=INF,cnt=1;
            int bonus=0;
            for(int i=1;i<=n;i++)
            {
                int nl=min(vs[i-1],vt[i-1]),nr=max(vs[i-1],vt[i-1]);
                if(i==1&&x==1&&nl==1) {nr=1; bonus++;}
                if(i==n&&y==1&&nr==n+m) {nl=n+m; bonus++;} 
                if(max(nl,l)>min(nr,r))
                {
                    cnt++;
                    l=nl+1; r=nr+1;
                }
                else
                {
                    l=max(nl,l)+1;
                    r=min(nr,r)+1;
                }
            }
            //printf("x=%d y=%d cnt=%d bonus=%d\n",x,y,cnt,bonus);
            ans=max(ans,n+m-1-2*cnt+bonus);
        }
    printf("%d\n",ans);
}