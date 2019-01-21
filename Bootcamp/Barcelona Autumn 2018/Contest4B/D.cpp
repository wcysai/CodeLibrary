/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-30 05:38:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
vector<int> v;
vector<ll> sum;
vector<int> newly,dummy;
const ll B=600;
char ch[5];
set<int> has;
void rebuild()
{
    int sz1=(int)newly.size(),sz2=(int)v.size();
    dummy.clear();
    int i=0,j=0;
    while(i<sz1||j<sz2)
    {
        if(j>=sz2||(i<sz1&&newly[i]<=v[j])) 
        {
            dummy.push_back(newly[i]);
            i++;
        }
        else
        {
            dummy.push_back(v[j]);
            j++;
        }
    }
    v.resize(dummy.size());
    for(int i=0;i<(int)dummy.size();i++) v[i]=dummy[i];
    sum.clear();int sz=v.size();sum.resize(sz);
    for(int i=0;i<sz;i++) if(i==0) sum[i]=v[i]; else sum[i]=sum[i-1]+v[i];
    newly.clear();
}
ll find_ans(int x)
{
    if(v.size()==0) return 0;
    int id=upper_bound(v.begin(),v.end(),x)-v.begin();
    if(id==0) return 0; else return sum[id-1];
}
int main()
{
    scanf("%d",&n);
    int lastans=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%s",ch);
        int x;
        if(ch[0]=='+')
        {
            scanf("%d",&x);x=(x+lastans)%INF;
            if(has.count(x)) {lastans=0; continue;}
            if(newly.size()==0) newly.push_back(x);
            else
            {
                if(!has.count(x)) 
                {
                    auto it=lower_bound(newly.begin(),newly.end(),x);
                    newly.insert(it,x);
                }
            }
            has.insert(x);
            lastans=0;
        }
        else
        {
            int l,r;scanf("%d%d",&l,&r);
            ll ans=find_ans(r)-find_ans(l-1);
            for(auto it:newly) 
            {
                if(it<l||it>r) continue;
                ans+=it;
            }
            printf("%lld\n",ans);lastans=ans%INF;
        }
        if(i%B==0) rebuild();
    }
    return 0;
}

