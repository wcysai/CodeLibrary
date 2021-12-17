#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,r,p,k;
string str;
vector<int> pos;
set<int> s;
vector<int> revive;
int main()
{
    scanf("%d%d%d%d%d",&n,&x,&r,&p,&k);
    cin>>str;
    ll res=0,ans=-INF;
    for(int i=0;i<k;i++) {s.insert(i); res+=1LL*p*(n-i);}
    int now=k;
    for(int i=0;i<n;i++) if(str[i]=='1') {revive.push_back(i); res-=1LL*r*(n-i);}
    res+=1LL*n*x;
    ans=res;
    for(int i=0;i<min(k,(int)revive.size());i++)
    {
        int x=revive[i];
        if(s.count(x))
        {
            s.erase(x);
            res+=1LL*r*(n-x);
        }
        else
        {
            res+=1LL*r*(n-x); res+=1LL*p*(n-x);
            int last=*(--s.end()); s.erase(last); res-=1LL*p*(n-last); 
        }
        ans=max(ans,res);
    }
    printf("%lld\n",ans);
}