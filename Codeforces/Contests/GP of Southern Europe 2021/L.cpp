#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXSQRTB 1000005
#define MAXL 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{
	cerr << " " << H;
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
#else
	#define debug(...) 42
#endif
typedef long long ll;
typedef pair<int,int> P;
bool is_prime_small[MAXSQRTB];
bool is_prime[MAXL];
vector<ll> prime;
void segment_sieve(ll a,ll b)
{
    for(ll i=0;(ll)i*i<=b;i++) is_prime_small[i]=true;
    for(ll i=0;i<=b-a;i++) is_prime[i]=true;
    for(ll i=2;(ll)i*i<=b;i++)
    {
        if(is_prime_small[i])
        {
            for(ll j=2*i;(ll)j*j<=b;j+=i) is_prime_small[j]=false;
            for(ll j=max(2LL,(a+i-1)/i)*i;j<=b;j+=i) is_prime[j-a]=false;
        }
    }
    for(ll i=0;i<=b-a;i++)
        if(is_prime[i]&&a+i!=1) prime.push_back(a+i);
}
int T;
ll L,R;
const int magic=1000000;
ll a[MAXN],bas[42];
int n;
int find_rank()
{
    memset(bas,0,sizeof(bas));
    int cnt=0;
    for(auto x:prime)
        for(int j=40;j>=0;j--)
        {
            if(x&(1ll<<j))
            {
                if(!bas[j])
                {
                    bas[j]=x;
                    cnt++;
                    break;
                }
                x^=bas[j];
            }
        }
    return cnt;
}
typedef unsigned long long ULL;
//to achieve best running time, sieve until 2/3 prime factors remaining
namespace pollardrho 
{
    ULL gcd(ULL a, ULL b) {return b ? gcd(b, a % b) : a;}

    ULL mulmod(ULL x,ULL y,ULL p)
    {
        ULL z=(long double)x/p*y;
        ULL res=(ULL)x*y-(ULL)z*p;
        return (res+p)%p;
    }

    ULL powmod(ULL b, ULL e, ULL m) 
    {
        ULL r = 1;
        while (e) 
        {
            if (e & 1) r = mulmod(r, b, m);
            b = mulmod(b, b, m);
            e >>= 1;
        }
        return r;
    }

    bool test(ULL n)
    {
        if (n < 3) return n==2;
        // ! The array a[] should be modified if the range of x changes.
        static const ULL a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23,  ULLONG_MAX};//works for 1e18
        ULL r = 0, d = n-1, x;
        while (~d & 1) d >>= 1, r++;
        for (int i=0; a[i] < n; i++)
        {
            x = powmod(a[i], d, n);
            if (x == 1 || x == n-1) goto next;
            for(int i=0;i<r;i++)
            {
                x = mulmod(x, x, n);
                if (x == n-1) goto next;
            }
            return false;
            next:;
        }
        return true;
    }

    map<ULL, int> mp;
    mt19937_64 gen(time(NULL));

    void PollardRho(ULL n) 
    {
        ULL c, x, y, d;
        while (n % 2 == 0) 
        {
            mp[2]++;
            n /= 2;
        }
        if (n == 1) return;

        if (test(n)) 
        {
            mp[n]++;
            return;
        }

        d = n;
        static int counter = 0;
        while (d == n) 
        {
            x = y = 2;
            d = 1;
            c = gen() % (n - 1) + 1;
            while (d == 1) 
            {
                counter++;
                x = (mulmod(x, x, n) + c) % n;
                y = (mulmod(y, y, n) + c) % n;
                y = (mulmod(y, y, n) + c) % n;
                d = gcd(x > y ? x - y : y - x, n);
            }
        }
        PollardRho(d);
        PollardRho(n / d);
    }

    void work(ULL n,int id) 
    {
        PollardRho(n);
        //for(auto p:mp) fact[id].push_back(p);
        mp.clear();
    }
}
void print(ll x)
{
    vector<int> v;
    while(x) v.push_back(x&1),x>>=1;
    reverse(v.begin(),v.end());
    for(auto y:v) printf("%d",y);
    puts("");
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&L,&R);
        if(R-L<magic)
        {
            prime.clear();
            segment_sieve(L,R);
            printf("%lld\n",1LL<<(find_rank()));
        }
        else
        {
            while(!pollardrho::test(L)) L++;
            while(!pollardrho::test(R)) R--;
            int id=-1;
            bool flag=false;
            for(int i=40;i>=0;i--)
            {
                if((!(L&(1LL<<i)))&&(R&(1LL<<i)))
                {
                    id=i;
                    break;
                }
                if((L&(1LL<<i))&&(R&(1LL<<i))) flag=true;
            }
        }
    }
    return 0;
}
