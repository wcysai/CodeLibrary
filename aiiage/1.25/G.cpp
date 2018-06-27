#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 10
using namespace std;
int n,k;
bool winner[MAXN];
struct scc
{
    int low[3],high[3];
    vector<int> num;
    scc(int x)
    {
        for(int i=0;i<3;i++)
        {
            int p;
            scanf("%d",&p);
            low[i]=p;
            high[i]=p;
        }
        num.clear();
        num.push_back(x);
    }
    bool operator<(const scc &x)const
    {
        int cnt=0;
        for(int i=0;i<3;i++)
            if(low[i]<=x.high[i]) cnt++;
        return cnt>=2?true:false;
    }
    void merge(const scc &x)
    {
        for(int i=0;i<3;i++)
        {
            low[i]=min(low[i],x.low[i]);
            high[i]=max(high[i],x.high[i]);
        }
        num.insert(num.end(),x.num.begin(),x.num.end());
    }
};
set<scc> s;
int main()
{
    scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
        scc q=scc(i);
        if(s.size())
        {
            auto lb=s.begin(),ub=s.end()--;
            for(auto it=s.begin();;it++)
                if(it==s.end()||q<(*it)) {lb=it; break;}
            if(lb==s.end()) ub=s.end(); 
            else
            for(auto it=s.end()--;;it--)
                if((it==lb)||(*it)<q) {ub=it; break;}
            while(lb!=ub)
            {
                q.merge(*lb);
                lb=s.erase(lb);
            }
        }
        s.insert(q);
    }
    memset(winner,false,sizeof(winner));
    for(int i=0;i<s.rbegin()->num.size();i++)
        winner[s.rbegin()->num[i]]=true;
    for(int i=0;i<n;i++)
        printf("%d\n",winner[i]?1:0);
    return 0;
}
