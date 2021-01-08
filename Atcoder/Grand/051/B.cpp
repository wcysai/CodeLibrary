#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<P> val[MAXN];
vector<int> dis;
set<int> x,y;
bool cmp(int x,int y)
{
    return val[50000+x].size()>val[50000+y].size();
}
vector<P> ans;
void check()
{
    dis.clear();
    vector<int> v1,v2,v3,v4;
    for(auto i:x)
        for(auto j:y)
        {
            val[50000+i-j].push_back(P(i,j));
            dis.push_back(i-j);
        }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    sort(dis.begin(),dis.end(),cmp);
    int s=0;
    for(int i=0;i<1000;i++)
    {
        s+=(int)val[50000+dis[i]].size();
        for(auto p:val[50000+dis[i]])
        {
            v1.push_back(p.F);
            v2.push_back(p.S);
            v3.push_back(p.F-p.S);
            v4.push_back(p.F+p.S);
            ans.push_back(P(p.F,p.S));
        }
    }
    sort(v1.begin(),v1.end()); v1.erase(unique(v1.begin(),v1.end()),v1.end());
    sort(v2.begin(),v2.end()); v2.erase(unique(v2.begin(),v2.end()),v2.end());
    sort(v3.begin(),v3.end()); v3.erase(unique(v3.begin(),v3.end()),v3.end());
    sort(v4.begin(),v4.end()); v4.erase(unique(v4.begin(),v4.end()),v4.end());
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
}
mt19937 wcy(time(NULL));
int main()
{
    while(x.size()<1000) 
    {
        int xs=wcy()%50000+1;
        x.insert(xs);
    }
    while(y.size()<1000) 
    {
        int xs=wcy()%50000+1;
        y.insert(xs);
    }
    check();
}