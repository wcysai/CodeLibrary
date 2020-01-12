#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
#define next dkaosdksao
using namespace std;
typedef long long ll;
typedef bitset<500005> bs;
int tot=1,n;
int trie[MAXN][26];
int cost[MAXN];
ll dp[MAXN];
vector<string> longstring;
vector<int> costs;
vector<bs> positions;
void insert(string &s,int c)
{
    int rt=1;
    for(int i=0;i<(int)s.size();i++)
    {
        int x=s[i]-'a';
        if(!trie[rt][x]) trie[rt][x]=++tot;
        rt=trie[rt][x];
    }
    if(cost[rt]==-1) cost[rt]=c; else cost[rt]=min(cost[rt],c);
}
int go(int pos,char ch)
{
    int x=ch-'a';
    if(!trie[pos][x]) return -1;
    pos=trie[pos][x];
    return pos;
}
bs kmp(string &a,string &b) // a=pattern, b=text
{
    int n=a.size();
    vector<int> next(n+1,0);
    for(int i=1;i<n;++i)
    {
        int j=i;
        while(j>0)
        {
            j=next[j];
            if(a[j]==a[i])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
    int m=b.size();
    bs p;
    for(int i=0,j=0;i<m;++i)
    {
        if(j<n&&b[i]==a[j])
        {
            j++;
        }
        else
        {
            while(j>0)
            {
                j=next[j];
                if(b[i]==a[j])
                {
                    j++;
                    break;
                }
            }
        }
        if(j==n)
        {
            p.set(i-n+1);
        }
    }
    return p;
}
const int threshold=1000;
string str;
int main()
{
    freopen("in.txt","r",stdin);
    clock_t startTime,endTime;
    startTime = clock();
    scanf("%d",&n);
    memset(cost,-1,sizeof(cost));
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int cost;
        scanf("%d",&cost);
        if(str.size()<=threshold) insert(str,cost);
        else 
        {
            longstring.push_back(str);
            costs.push_back(cost);
        }
    }
    cin>>str;
    for(auto t:longstring) positions.push_back(kmp(t,str));
    for(int i=0;i<=(int)str.size();i++) dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<(int)str.size();i++)
    {
        if(dp[i]==INF) continue;
        int pos=1;
        for(int j=1;j<=threshold&&i+j-1<(int)str.size();j++)
        {
            pos=go(pos,str[i+j-1]);
            if(pos==-1) break;
            if(cost[pos]!=-1) dp[i+j]=min(dp[i+j],dp[i]+cost[pos]);
        }
        for(int j=0;j<(int)longstring.size();j++)
        {
            string &t=longstring[j];
            if(i+(int)t.size()-1>=(int)str.size()) continue;
            bs &p=positions[j];
            if(!p.test(i)) continue;
            dp[i+(int)t.size()]=min(dp[i+(int)t.size()],dp[i]+costs[j]);
        }
    }
    if(dp[(int)str.size()]==INF) puts("-1"); else printf("%lld\n",dp[(int)str.size()]);
    endTime = clock();
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}