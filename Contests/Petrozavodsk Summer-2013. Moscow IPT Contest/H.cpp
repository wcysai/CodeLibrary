#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[15];
struct node
{
    int cnt[12];
    int mult; int sum;
    int digits;
    ll ways;
    bool les;
    //digit=fact.size()+mult-sum
};
vector<node> save[MAXN];
int val[12];
int chosen;
ll s[MAXN];
ll calc(int cnt[],int digits)
{
    for(int i=1;i<=9;i++) if(cnt[i]<0) return 0;
    vector<int> tmp;
    int sum=0,cur=digits;
    if(digits==0) return 1;
    for(int i=2;i<=9;i++) sum+=cnt[i];
    for(int i=1;i<=sum;i++)
    {
        tmp.push_back(digits);
        digits--;
    }
    for(int i=2;i<=9;i++)
    {
        int x=fact[cnt[i]];
        for(auto &v:tmp)
        {
            if(x==1) break;
            int g=__gcd(v,x);
            v/=g; x/=g;
        }
    }
    ll ret=1;
    for(auto v:tmp)
    {
        if(INF/ret<=v) return INF;
        ret*=v;
    }
    return ret;
}
void dfs(int cur,int mult,int sum)
{
    if(cur==10)
    {
        node newnode;
        for(int i=2;i<=10;i++) newnode.cnt[i]=val[i];
        newnode.mult=mult; newnode.sum=sum;
        newnode.cnt[1]=mult-sum;
        newnode.digits=chosen+mult-sum;
        newnode.ways=calc(val,newnode.digits);
        newnode.les=false;
        save[newnode.digits].push_back(newnode);
        s[newnode.digits]+=newnode.ways;
        if(s[newnode.digits]>=INF) s[newnode.digits]=INF;
        return;
    }
    int tmp=chosen,_mult=mult,_sum=sum;
    for(int i=1;;i++)
    {
        dfs(cur+1,_mult,_sum);
        if(_mult*cur>1000) break;
        _mult*=cur; _sum+=cur;
        val[cur]++;
        chosen+=1;
    }
    val[cur]=0;
    chosen=tmp;
}
ll n;
string ans;
int main()
{
    fact[0]=1;
    for(int i=1;i<=12;i++) fact[i]=fact[i-1]*i;
    dfs(2,1,0);
    scanf("%lld",&n);
    int id=-1;
    for(int i=1;i<=1000;i++)
    {
        if(s[i]>=n)
        {
            id=i;
            break;
        }
        else n-=s[i];
    }
    ll ss=0;
    for(int i=id;i>=1;i--)
    {
        for(auto &p:save[id]) p.digits--;
        for(int j=1;j<=9;j++)
        {
            for(auto &p:save[id])
            {
                if(p.les) continue;
                p.cnt[j]--;
                p.ways=calc(p.cnt,p.digits);
                ss+=p.ways;
                if(ss>=INF) ss=INF;
                p.cnt[j]++;
            }
            if(ss>=n)
            {
                ans+=(char)('0'+j);
                for(auto &p:save[id])
                {
                    if(p.les) continue;
                    if(p.cnt[j]) {ss-=p.ways; p.cnt[j]--;}
                    else p.les=true;
                }
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
