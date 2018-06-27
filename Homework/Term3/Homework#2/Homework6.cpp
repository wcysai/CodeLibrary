#include<bits/stdc++.h>
#define MAXV 10050
#define MAXE 50050
#define INF 100000000000000
using namespace std;
typedef long long ll;
struct edge{int from,to,cost;};
vector<edge> es;
bool cmp(edge x,edge y)
{
    return x.cost<y.cost;
}
ll d[MAXV];
int V,E,query;
pair<int,ll> rec[MAXV];
int main()
{
    scanf("%d",&query);
    while(query--)
    {
        scanf("%d %d",&V,&E);
        es.clear();
        for(int i=0;i<E;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            x--,y--;
            es.push_back((edge){x,y,z});
            es.push_back((edge){y,x,z});
        }
        sort(es.begin(),es.end(),cmp);
        fill(d,d+V,INF);
        d[0]=0;
        int num=0;
        int save=0;
        for(int i=0;i<es.size();i++)
        {
            edge e=es[i];
            if(e.cost!=save)
            {
                for(int j=0;j<num;j++)
                    d[rec[j].first]=min(d[rec[j].first],rec[j].second);
                save=e.cost;
                num=0;
            }
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost)
            {
                rec[num].first=e.to;
                rec[num].second=d[e.from]+(ll)e.cost;;
                num++;
            }
        }
        for(int j=0;j<num;j++)
            d[rec[j].first]=min(d[rec[j].first],rec[j].second);
        num=0;
        if(d[V-1]==INF) printf("No answer\n"); else printf("%I64d\n",d[V-1]);
    }
    return 0;
}
