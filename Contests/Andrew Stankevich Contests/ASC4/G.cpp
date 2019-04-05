#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 25
#define MAXK 30
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
int n,m,maxilen;
db score[MAXN];
string str;
string names[MAXN];
int cnt[MAXN];
int k[MAXM],prob[MAXM];
P res[MAXN];
int inpc[MAXN];
int penalty[MAXN][MAXK];
bool solved[MAXN][MAXK];
char ss[5],sss[5];
struct team
{
    string name;
    db score;
}t[MAXN];
struct node
{
    int sl,pty,id,rk;
};
bool cmp(node x,node y)
{
    if(x.sl!=y.sl) return x.sl>y.sl;
    return x.pty<y.pty;
}
bool cmp2(team x,team y)
{
    return x.score>y.score;
}
int main()
{
    freopen("ranking.in","r",stdin);
    freopen("ranking.out","w",stdout);
    scanf("%d",&n);getchar();
    for(int i=1;i<=n;i++)
    {
        getline(cin,t[i].name);
        maxilen=max(maxilen,(int)t[i].name.size());
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&k[i]);
        int b=k[i]-2,a=2*b+2;
        memset(inpc,false,sizeof(inpc));
        for(int j=1;j<=n;j++) res[j]=P(0,0);
        for(int j=0;j<k[i];j++)
        {
            int x;scanf("%d",&x);
            inpc[x]=true;
        }
        scanf("%d",&prob[i]);
        int runs,id,subtime,pid;
        memset(solved,false,sizeof(solved));
        memset(penalty,0,sizeof(penalty));
        scanf("%d",&runs);
        for(int j=0;j<runs;j++)
        {
            scanf("%d",&id); 
            scanf("%s",ss); 
            scanf("%d",&subtime); 
            scanf("%s",sss); 
            pid=ss[0]-'A'+1;
            if(solved[id][pid]) continue;
            if(sss[0]=='+')
            {
                solved[id][pid]=true;
                res[id].F++;
                res[id].S+=20*penalty[id][pid]+subtime;
            }
            else penalty[id][pid]++;
        }
        vector<node> v; v.clear();
        int maxi=0;
        for(int j=1;j<=n;j++)
            if(inpc[j]) 
            {
                maxi=max(maxi,res[j].F);
                v.push_back((node){res[j].F,res[j].S,j});
            }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<(int)v.size();i++)
        {
            if(i!=0&&v[i].sl==v[i-1].sl&&v[i].pty==v[i-1].pty) v[i].rk=v[i-1].rk;
            else v[i].rk=i+1;
            cnt[v[i].id]++;
            if(maxi==0) continue;
            else
            {
                db sc=((db)v[i].sl/maxi)*(db)a/((db)v[i].rk+b);
                score[v[i].id]+=sc;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        t[i].score=(cnt[i]==0?0:score[i]/cnt[i]);
    }
    sort(t+1,t+n+1,cmp2);
    for(int i=1;i<=n;i++)
    {
        cout<<t[i].name;
        for(int j=0;j<maxilen-(int)t[i].name.size()+1;j++) cout<<' ';
        printf("%.4f\n",t[i].score);
    }
    return 0;
}

