#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int T,n;
bool f=false;
vector<int> G[MAXN];
int deg[MAXN];
vector<int> ans;
int find_ans(int v,int p)
{
	int cnt=0,res=0;
    vector<int> vec; vec.clear();
	for(auto to:G[v])
	{
		if(to==p) continue;
		int val=find_ans(to,v);
		if(val==0) cnt++,vec.push_back(to);
		res+=val;
	}
	if(cnt>0) 
    {
        while(vec.size()>1) ans.push_back(vec.back()),vec.pop_back();
        return res+cnt-1; 
    }
    else return res;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans.clear(); memset(deg,0,sizeof(deg));
	    scanf("%d",&n); for(int i=1;i<=n;i++) G[i].clear();
	    for(int i=0;i<n-1;i++)
	    {
		    int x,y;
		    scanf("%d%d",&x,&y);
		    G[x].push_back(y);
		    G[y].push_back(x);
		    deg[x]++;deg[y]++;
	    }
	    bool f=false;
	    int res;
	    for(int i=1;i<=n;i++)
	    {
		    if(deg[i]>=3)
		    {
			    f=true;
			    res=find_ans(i,0);
			    break;
		    }
	    }
	    if(!f)
	    {
            for(int i=1;i<=n;i++) 
            {
                if(deg[i]==1)
                {
                    printf("1\n%d\n",i);
                    break;
                }
            }
		    continue;
	    }
	    printf("%d\n",res);
        sort(ans.begin(),ans.end());
        for(auto v:ans) printf("%d ",v);
        puts("");
    }
	return 0;
}
