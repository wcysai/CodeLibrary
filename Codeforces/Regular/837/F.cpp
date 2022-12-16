#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot,cnt,a[MAXN],root[MAXN];
int sz,lson[MAXM],rson[MAXM];
ull s[MAXM];
vector<int> pos[MAXN];
vector<int> dis;
ull mi[MAXN];
mt19937_64 rice(time(NULL)); 
void merge(int k)
{
    s[k]=s[lson[k]]^s[rson[k]];
}
void insert(int &k,int last,int l,int r,int p,uint z)
{
    k=++tot;
    s[k]=s[last];
    if(l==r) {s[k]^=z; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,z);
    else insert(rson[k],rson[last],mid+1,r,p,z);
    merge(k);
}
ull query(int k1,int k2,int l,int r)
{
    if(l==r) return dis[l-1];
    int mid=(l+r)/2;
    if(s[lson[k1]]!=s[lson[k2]]) return query(lson[k1],lson[k2],l,mid); else return query(rson[k1],rson[k2],mid+1,r);
}
int solve(int l,int r)
{
    if(s[root[r]]==s[root[l-1]]) return 0;
    return query(root[l-1],root[r],1,sz);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]); dis.push_back(a[i]);
    }
    scanf("%d",&q);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        a[i]=id;
        pos[id].push_back(i);
    }
    sz=(int)dis.size();
    for(int i=1;i<=sz;i++) mi[i]=rice();
    int last=0;
    for(int i=1;i<=n;i++)
        insert(root[i],root[i-1],1,sz,a[i],mi[a[i]]);
    int ans=0;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l^=ans; r^=ans;
        ans=solve(l,r);
        printf("%d\n",ans);
    }
    return 0;
}




