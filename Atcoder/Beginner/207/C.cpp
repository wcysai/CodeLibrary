#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l[MAXN],r[MAXN],t[MAXN];
//a<=k(cd-b)
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&t[i],&l[i],&r[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int lb=max(l[i],l[j]),rb=min(r[i],r[j]);
            if(rb>lb) ans++;
            else if(lb==rb)
            {
                bool f=true;
                if(lb==l[i]&&(t[i]==3||t[i]==4)) f=false;
                if(lb==l[j]&&(t[j]==3||t[j]==4)) f=false;
                if(rb==r[i]&&(t[i]==2||t[i]==4)) f=false;
                if(rb==r[j]&&(t[j]==2||t[j]==4)) f=false;
                if(f) ans++;
            }
        }
    printf("%d\n",ans);
    return 0;
}