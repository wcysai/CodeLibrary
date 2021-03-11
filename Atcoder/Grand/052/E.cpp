#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,t;
int a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&n);
    cin>>s; cin>>t;
    a[0]=s[0]-'a';
    for(int i=1;i<n;i++) if((s[i]-s[i-1]+3)%3==1) a[i]=a[i-1]+1; else a[i]=a[i-1]-1;
    b[0]=t[0]-'a';
    for(int i=1;i<n;i++) if((t[i]-t[i-1]+3)%3==1) b[i]=b[i-1]+1; else b[i]=b[i-1]-1;
    if((a[0]-b[0])&1)
    {
        for(int i=0;i<n;i++) b[i]+=3;
    }
    vector<int> vec; vec.clear();
    for(int i=0;i<n;i++) vec.push_back(a[i]-b[i]);
    sort(vec.begin(),vec.end());
    int val=vec[n/2]/6*6;
    if(val>vec[n/2]) val-=6;
    ll ans1=0,ans2=0;
    for(auto x:vec)
    {
        ans1+=max(x-val,val-x);
        ans2+=max(x-val-6,val+6-x);
    }
    printf("%lld\n",min(ans1,ans2)/2);
    return 0;
}