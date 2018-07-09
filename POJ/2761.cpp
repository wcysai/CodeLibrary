/*************************************************************************
    > File Name: 2761.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-09 09:13:43
 ************************************************************************/

#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#define MAXN 100005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot,cnt,a[MAXN],root[MAXN],save[MAXN];
int lson[MAXM],rson[MAXM],sum[MAXM];
vector<int> pos;
void merge(int k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
}
void build(int &k,int l,int r)
{
    k=++tot;
    if(l==r) return;
    int mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
    merge(k);
}
void insert(int &k,int last,int l,int r,int p)
{
    k=++tot;
    sum[k]=sum[last];
    if(l==r) {sum[k]++; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p);
    else insert(rson[k],rson[last],mid+1,r,p);
    merge(k);
}
int query(int k1,int k2,int l,int r,int num)
{
    if(l==r) return l;
    int x=sum[lson[k2]]-sum[lson[k1]];
    int mid=(l+r)/2;
    if(num>=x) return query(rson[k1],rson[k2],mid+1,r,num-x);
    else return query(lson[k1],lson[k2],l,mid,num);
}
set<int> s;
map<int,int> mp;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos.push_back(a[i]);
    }
    sort(pos.begin(),pos.end());
    pos.erase(unique(pos.begin(),pos.end()),pos.end());
    int p=(int)pos.size();
    build(root[++cnt],1,p);
    for(int i=1;i<=n;i++)
    {
        cnt++;
        int x=lower_bound(pos.begin(),pos.end(),a[i])-pos.begin()+1;
        insert(root[cnt],root[cnt-1],1,p,x);
    }
    for(int i=1;i<=q;i++)

    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",pos[query(root[l],root[r+1],1,p,k-1)-1]);
    }
    return 0;
}
