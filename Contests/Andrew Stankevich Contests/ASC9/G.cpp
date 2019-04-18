#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
vector<int> v;
short last[MAXN];
vector<short> nxt[MAXN];
vector<int> ans[4];
int find_next(int i,int j)
{
    if(i>n||nxt[j].size()==0||nxt[j].back()<i) return n+1;
    int id=lower_bound(nxt[j].begin(),nxt[j].end(),i)-nxt[j].begin();
    return nxt[j][id];
}
int main()
{
    freopen("rhymes.in","r",stdin);
    freopen("rhymes.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++) a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    int sz=(int)v.size();
    for(int i=1;i<=n;i++) nxt[a[i]].push_back(i);
    int now=1;
    while(now<=n)
    {
        int pos1=INF,id1=-1,pos2=INF,id2=-1,pos4=INF,id4=-1;
        for(int j=1;j<=sz;j++)
        {
            int x=find_next(find_next(now,j)+1,j),y=find_next(find_next(x+1,j)+1,j);
            if(x>n) continue;
            if(x<pos1)
            {
                id2=id1; pos2=pos1;
                id1=j; pos1=x;
            }
            else if(x<pos2)
            {
                id2=j; pos2=x;
            }
            if(y<=n&&y<pos4) {pos4=y; id4=j;}
        }
        if(pos2==INF&&pos4==INF) break;
        if(pos4<max(pos1,pos2))
        {
            int x=find_next(now,id4); ans[0].push_back(x); x++;
            x=find_next(x,id4); ans[1].push_back(x); x++;
            x=find_next(x,id4); ans[2].push_back(x); x++;
            x=find_next(x,id4); ans[3].push_back(x); x++;
            now=x;
        }
        else
        {
            vector<int> tmp; tmp.clear();
            int x=find_next(now,id1); tmp.push_back(x); x++;
            x=find_next(x,id1); tmp.push_back(x); x++;
            x=find_next(now,id2); tmp.push_back(x); x++;
            x=find_next(x,id2); tmp.push_back(x); x++;
            sort(tmp.begin(),tmp.end());
            now=x;
            for(int i=0;i<4;i++) ans[i].push_back(tmp[i]);
        }
    }
    printf("%d\n",(int)ans[0].size());
    for(int i=0;i<(int)ans[0].size();i++)
    {
        for(int j=0;j<4;j++) printf("%d ",ans[j][i]);
        puts("");
    }
    return 0;
}
