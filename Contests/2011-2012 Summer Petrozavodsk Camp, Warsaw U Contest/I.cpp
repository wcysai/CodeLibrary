#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k,n[MAXN];
vector<P> v;
struct node
{
    int c1,v1,c2,v2;
};
node last[55];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            int y;
            scanf("%d",&y);
            v.push_back(P(y,i));
        }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=50;i++) last[i].c1=last[i].v1=last[i].c2=last[i].v2=-1;
    for(int i=(int)v.size()-1;i>=0;i--)
    {
        int color=v[i].S,val=v[i].F;
        if(last[color].v1!=-1&&last[color].v2-last[color].v1<val)
        {
            printf("%d %d %d %d %d %d\n",color,val,last[color].c1,last[color].v1,last[color].c2,last[color].v2);
            return 0;
        }
        if((i!=(int)v.size()-1)&&(v[i].S!=v[i+1].S))
        {
           for(int j=1;j<=50;j++)
           {
               if(j==v[i].S||j==v[i+1].S) continue;
               if(last[j].v1==-1||v[i+1].F-v[i].F<last[j].v2-last[j].v1)
               {
                   last[j].c1=v[i].S; last[j].v1=v[i].F;
                   last[j].c2=v[i+1].S; last[j].v2=v[i+1].F;
               }
           }
        }
    }
    puts("NIE");
    return 0;
}
