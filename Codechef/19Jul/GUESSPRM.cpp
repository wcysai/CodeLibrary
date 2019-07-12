#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int T;
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
string str;
mt19937 wcy(time(NULL));
int main()
{
    int p=sieve(40000);
    scanf("%d",&T);
    while(T--)
    {
        printf("1 32767\n");
        fflush(stdout);
        int x,y;
        scanf("%d",&x);
        int res=32767*32767-x;
        vector<int> v; v.clear();
        for(int i=0;i<p;i++)
        {
            if(res==1) break;
            if(res%prime[i]==0)
            {
                v.push_back(prime[i]);
                while(res%prime[i]==0) res/=prime[i];
            }
        }
        if(res>1) v.push_back(res);
        int cur;
        set<int> s;
        do
        {
            s.clear();
            cur=wcy()%INF+1;
            for(auto pr:v) s.insert(1LL*cur*cur%pr);
            if(s.size()==v.size()) break;
        }while(true);
        printf("1 %d\n",cur);
        fflush(stdout);
        scanf("%d",&y);
        int ans=-1;
        for(auto pr:v) 
        {
            if(pr>x&&pr>y&&1LL*cur*cur%pr==y)
            {
                ans=pr;
            }
        }
        printf("2 %d\n",ans);
        fflush(stdout);
        cin>>str;
        assert(str[0]=='Y');
    }
    return 0;
}

