#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int p[1002];

int find(int x) {return p[x]==x ? x : p[x]=find(p[x]);}

bool same(int x,int y) {return find(x)==find(y);}
int abv(int x){return max(x,-x);}

void unite(int x,int y)
{
    int u = find(x);
    int v = find(y);
    if(u != v) p[u] = v;
}
int main()
{
    int n,d,m,k;
    char c;
    int coord[1002][2],jud[1002];
    memset(jud,0,sizeof(jud));
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=n;i++)
        scanf("%d %d",&coord[i][0],&coord[i][1]);
    while(scanf("%c %d",&c,&m)!=(EOF))
    {

        if(c=='O')
        {
            jud[m]=1;
            for(int i=1;i<=n;i++)
            {
                 if(i!=m&&jud[i]&&(coord[m][0]-coord[i][0])*(coord[m][0]-coord[i][0])+(coord[m][1]-coord[i][1])*(coord[m][1]-coord[i][1])<=d*d)
                 {
                    unite(m,i);
                 }
            }
        }
        if(c=='S')
        {
            scanf("%d",&k);
            if(same(m,k)) printf("SUCCESS\n"); else printf("FAIL\n");
        }

    }
return 0;
}