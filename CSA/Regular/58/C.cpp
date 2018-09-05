#include<bits/stdc++.h>
#define MAXN 400300
using namespace std;
int n,m;
vector<int> s[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        s[2*i].push_back(i);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        s[x+y].push_back(min(x,y));
    }
    int ans=0;
    for(int i=2;i<=2*n;i++)
    {
        sort(s[i].begin(),s[i].end());
        int cnt=0;
        bool f=false;
        int t=0;
        for(int j=0;j<s[i].size();j++)
            if(s[i][j]==i/2) {f=true; t=j; break;}
        if(!f) continue;
        cnt=i%2==0?1:2;
        for(int j=t-1;j>=0;j--)
            if(s[i][j]==s[i][j+1]-1) cnt+=2; else break;
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}

