

int T;
ll a,b,c,d;
ll n,ans;
map<ll,ll> mp; 
ll solve(ll x)
{
    if(x==0) return 0;
    if(x==1) return d;
    if(mp.find(x)!=mp.end()) return mp[x];
    ll res=INF;
    if(INF/x>d) res=d*x;
    res=min(res,solve(x/2)+d*(x%2)+a);
    res=min(res,solve((x+1)/2)+d*(2-x%2)+a);
    res=min(res,solve(x/3)+d*(x%3)+b);
    res=min(res,solve((x+2)/3)+d*(3-x%3)+b);
    res=min(res,solve(x/5)+d*(x%5)+c);
    res=min(res,solve((x+4)/5)+d*(5-x%5)+c);
    return mp[x]=res;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        mp.clear();
        scanf("%lld",&n);
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        printf("%lld\n",solve(n));
    }
    return 0;
}