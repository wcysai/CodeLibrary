#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q;
vector<int> dis;
set<P> ms;
int op[MAXN],x[MAXN];
struct node
{
    int type,l,r;
};
vector<node> vv;
int bit[2*MAXN+1],n;
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
    while(i<=2*MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&op[i],&x[i]);
        if(op[i]==1)
        {
            ms.insert(P(x[i],i));
            auto it=ms.find(P(x[i],i));
            if(it!=ms.begin())
            {
                it--;
                int dif=x[i]-it->F,sum=x[i]+it->F;
                vv.push_back((node){1,dif+1,sum-1});
                it++;
            }
            it++;
            if(it!=ms.end())
            {
                int dif=it->F-x[i],sum=it->F+x[i];
                vv.push_back((node){1,dif+1,sum-1});
            }
            it--;
            if(it!=ms.begin())
            {
                it--;
                int p=it->F;
                it++;
                it++;
                if(it!=ms.end())
                {
                    int q=it->F;
                    int dif=q-p,sum=q+p;
                    vv.push_back((node){2,dif+1,sum-1});
                }
            }
        }
        else if(op[i]==2)
        {
            auto it=ms.lower_bound(P(x[i],0));
            if(it!=ms.begin())
            {
                it--;
                int dif=x[i]-it->F,sum=x[i]+it->F;
                vv.push_back((node){2,dif+1,sum-1});
                it++;
            }
            it++;
            if(it!=ms.end())
            {
                int dif=it->F-x[i],sum=it->F+x[i];
                vv.push_back((node){2,dif+1,sum-1});
            }
            it--;
            if(it!=ms.begin())
            {
                it--;
                int p=it->F;
                it++;
                it++;
                if(it!=ms.end())
                {
                    int q=it->F;
                    int dif=q-p,sum=q+p;
                    vv.push_back((node){1,dif+1,sum-1});
                }
                it--;
            }
            ms.erase(it);
        }
        if(op[i]==3) 
        {
            vv.push_back((node){3,x[i],0});
        }
    }
    for(auto p:vv)
    {
        if(p.type==3) dis.push_back(p.l);
        else {dis.push_back(p.l); dis.push_back(p.r+1);}
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(auto p:vv)
    {
        p.l=lower_bound(dis.begin(),dis.end(),p.l)-dis.begin()+1;
        p.r=lower_bound(dis.begin(),dis.end(),p.r+1)-dis.begin()+1;
        if(p.type==1)
        {
            add(p.l,1);
            add(p.r,-1);
        }
        else if(p.type==2)
        {
            add(p.l,-1);
            add(p.r,1);
        }
        else
        {
            if(sum(p.l)) puts("Yes"); else puts("No");
        }
    }
    return 0;
}