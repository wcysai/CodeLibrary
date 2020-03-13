#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int n,x,y;
vector<P> v;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v.push_back(P(x,0)); v.push_back(P(y,1));
    }
    sort(v.begin(),v.end());
    int cnt=0,ans=0;
    for(auto p:v)
    {
        if(!p.second) cnt++; else cnt--;
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}