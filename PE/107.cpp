#include<bits/stdc++.h>
#define MAXV 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string str;
ll cost[MAXV][MAXV];
ll mincost[MAXV];
bool used[MAXV];
ll V;
ll prim()
{
    for(ll i=0;i<V;i++)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    ll res=0;
    while(true)
    {
        ll v=-1;
        for(ll u=0;u<V;u++)
          if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        for(ll u=0;u<V;u++)
            mincost[u]=min(mincost[u],cost[v][u]);
    }
    return res;
}
int main()
{
	freopen("p107_network.txt","r",stdin);
	V=40;
	ll t=0,sum=0;
	while(cin>>str)
	{
		str+=',';
		//cout<<str<<endl;
		ll n=str.size();
		ll tt=0,now=0;
		for(ll i=0;i<n;i++)
		{
			if(str[i]==',')
			{
				if(str[i-1]=='-')
				{
					cost[t][tt]=INF;
					tt++;
					now=i+1;
				}
				else
				{
					ll num=0;
					for(ll j=now;j<=i-1;j++)
						num=num*10+str[j]-'0';
					cost[t][tt]=num;
					//printf("%I64d %I64d\n",tt,num);
					sum+=num;
					tt++;
					now=i+1;
				}
			}
		}
		t++;
	}
	sum/=2;
	printf("%I64d\n",sum-prim());
	fclose(stdin);
	return 0;
}