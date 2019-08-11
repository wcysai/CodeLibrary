#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int N,K,ans,cnt;
string cur;
string str[MAXN];
bool cmp(int id)
{
    int sza=(int)cur.size(),szb=(int)str[id].size();
    int sz=min(sza,szb);
    for(int i=0;i<sz;i++)
    {
        if(cur[sza-1-i]!=str[id][szb-1-i])
        {
            if(cur[sza-1-i]=='W') return false;
            else return true;
        }
    }
    return true;
}
void dfs(int now,int pos)
{
    if(now==K)
    {
        ans=max(ans,cnt);
        return;
    }
    if(cmp(pos))
    {
        cur+='W'; str[pos]+='B'; cnt++;
        dfs(now+1,(pos+1)%N);
        cur.pop_back();str[pos].pop_back(); cnt--;
    }
    else
    {
        cur+='B'; str[pos]+='W';
        dfs(now+1,(pos+1)%N);
        cur.pop_back();str[pos].pop_back();
    }
    if(now+2<=K)
    {
        if(cmp(pos))
        {
            cur+="WB"; str[pos]+="BW";
        }
        else
        {
            cur+="BW"; str[pos]+="WB";
        }
        cnt++;
        dfs(now+2,(pos+1)%N);
        cur.pop_back(); cur.pop_back(); str[pos].pop_back(); str[pos].pop_back(); cnt--;
    }
}

int main()
{
    freopen("checkers.in","r",stdin);
    freopen("checkers.out","w",stdout);
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) cin>>str[i];
    cur="";
    ans=0; cnt=0;
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}
