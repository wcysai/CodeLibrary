#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int ans=INF;
vector<P> v; 
void solve()
{
    v.clear();
    int type=-1,cnt=0;
    for(int i=0;i<n;i++)
    {
        int cur=0;
        if((str[i]-'0'+i)&1) cur=0; else cur=1;
        if(type==-1||type==cur) cnt++; else {v.push_back(P(type,cnt)); cnt=1;}
        type=cur;
    }
    if(cnt) v.push_back(P(type,cnt));
    int curans=0;
    int flag=0;
    for(auto p:v)
    {
        if(p.F==1)
        {
            if((flag+p.S)&1) {curans++; flag=1;}
            else {curans++; flag=0;}
        }
        else
        {
            if(flag&&((flag+p.S)%2==0)) {curans++; flag=0;} 
        }
    }
    if(flag) curans++;
    ans=min(ans,curans);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str; ans=INF;
        solve();
        for(int i=0;i<n;i++) str[i]='0'+'1'-str[i];
        solve();
        printf("%d\n",ans);
    }
    return 0;
}