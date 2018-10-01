/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 18:20:12
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

unordered_map<int,int>mp;
int p,q,a,b;
int n,m,ans,t;
ll now;
bool flag;

int fast_pow(int x)
{
    ll sum = 1, aa = a;
    while (x>0)
    {
        if (x&1) 
        {
            sum = sum*aa;
            if(sum>=p) sum%=p;
        }
        x=x>>1;
        aa=aa*aa;
        if(aa>=p) aa%=p;
    }
    return sum;
}
int main()
{
    scanf("%d%d",&p,&q);
    m=ceil(sqrt(p));
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&a,&b);
        if(b==1) {puts("0"); continue;}
        if(a%p==0)
        {
            if(b==1) puts("0");
            else if(b==0) puts("1");
            else puts("-1");
            continue;
        }
        if(b==0) {puts("-1"); continue;}
        mp.clear();
        flag = false;
        now = b%p;       
        mp[now] = 0;
        for(int i=1;i<=m;++i)
        {
            now = now*a;
            if(now>=p) now%=p;
            mp[now] = i;
        }
        t = fast_pow(m);
        now = 1;
        for(int i=1;i<=m;++i)   
        {
            now = now*t;
            if(now>=p) now%=p;
            if(mp[now])
            {
                flag = true;
                ans = (1LL*i*m-mp[now])%p;
                if(ans<0) ans+=p;
                printf("%d\n",ans);
                break;
            }
        }
        if(!flag) puts("-1");
    }
    return 0;
}
