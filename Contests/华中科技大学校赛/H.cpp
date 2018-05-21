#include<bits/stdc++.h>
#define MAXN 100005
#define MAXQ 10005
#define INF 1000000000
#define MOD 1000000007
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int bit[MAXN+1],n,w;
struct rec
{
    int x,y,h;
};
P query[MAXQ*4];
int save[MAXQ][4],ans[MAXQ*4];
rec op[MAXN];
map<P,int> mp;
bool cmp(rec a,rec b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&w);
    int tot1=0,tot2=0;
    for(int i=0;i<n;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d%d",&op[tot1].x,&op[tot1].y,&op[tot1].h);
            tot1++;
        }
        else
        {
            scanf("%d%d%d%d",&save[tot2][0],&save[tot2][1],&save[tot2][2],&save[tot2][3]);
            query[tot2*4]=P(save[tot2][0]-1,save[tot2][1]-1);
            query[tot2*4+1]=P(save[tot2][0]-1,save[tot2][3]);
            query[tot2*4+2]=P(save[tot2][2],save[tot2][1]-1);
            query[tot2*4+3]=P(save[tot2][2],save[tot2][3]);
            tot2++;
        }
    }
    memset(bit,0,sizeof(bit));
    sort(query,query+tot2*4);
    sort(op,op+tot1,cmp);
    printf("%d\n",tot2*4);
    int tt=0;
    for(int i=0;i<tot1;i++)
    {
        if(tt>=tot2*4) break;
        while(query[tt].x<op[i].x&&tt<tot2*4)
        {
            ans[tt]=sum(query[tt].y);
            printf("%d %d %d\n",query[i].x,query[i].y,ans[i]);
            tt++;
        }
        printf("op %d %d\n",op[i].x,op[i].y);
        add(op[i].y,op[i].h);
    }
    for(int i=tt;i<tot2*4;i++) 
    {
        ans[i]=sum(query[i].y);
        printf("%d %d %d\n",query[i].x,query[i].y,ans[i]);
    }
    for(int i=0;i<4*tot2;i++)
    {
        mp[P(query[i].x,query[i].y)]=ans[i];
    }
    for(int i=0;i<tot2;i++)
    {
        int res1=mp[P(save[i][0]-1,save[i][1]-1)];
        int res2=mp[P(save[i][0]-1,save[i][3])];
        int res3=mp[P(save[i][2],save[i][1]-1)];
        int res4=mp[P(save[i][2],save[i][3])];
        printf("%d\n",res4-res3-res2+res1);
    }
    return 0;
}
