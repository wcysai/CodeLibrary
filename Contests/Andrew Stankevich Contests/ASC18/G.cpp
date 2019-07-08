#include<bits/stdc++.h>
#define MAXN 150005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str;
int r[MAXN+1];
int sa[MAXN],lcp[MAXN];
int c[MAXN],t1[MAXN],t2[MAXN];
void construct_sa(string S,int *sa) 
{
    int n=S.length()+1;
    int m=130;
    int i,*x=t1,*y=t2;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=S[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1) {
        int p=0;
        for(i=n-k;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=0;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1; x[sa[0]]=0;
        for(i=1;i<n;i++) 
            x[sa[i]]=y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}
void construct_lcp(string S,int *sa,int *lcp)
{
    int n=S.length();
    for(int i=0;i<=n;i++) r[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++)
    {
        int j=sa[r[i]-1];
        if(h>0) h--;
        for(;j+h<n&&i+h<n;h++)
        {
            if(S[j+h]!=S[i+h]) break;
        }
        lcp[r[i]]=h;
    }
}
int L[MAXN],R[MAXN];
int st[MAXN];
int main()
{
    freopen("refrain.in","r",stdin);
    freopen("refrain.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        str+=(char)('a'+x-1);
    }
    construct_sa(str,sa);
    construct_lcp(str,sa,lcp);
    int t=0;
	for(int i=1;i<=n;i++)
	{
		while(t>0&&lcp[st[t-1]]>=lcp[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=n;i>=1;i--)
	{
		while(t>0&&lcp[st[t-1]]>=lcp[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
    ll maxi=-1;
    int pos=-1;
    for(int i=1;i<=n;i++)
    {
        int len=(R[i]-L[i]);
        if(1LL*len*lcp[i]>maxi)
        {
            maxi=1LL*len*lcp[i];
            pos=i;
        }
    }
    if(maxi<n)
    {
        printf("%d\n%d\n",n,n);
        for(int i=0;i<n;i++) printf("%d ",(int)(str[i]-'a'+1));
        return 0;
    }
    int x=lcp[pos];
    pos=sa[pos-1];
    printf("%lld\n%d\n",maxi,x);
    for(int i=pos;i<pos+x;i++) printf("%d ",(int)str[i]-'a'+1);
    return 0;
}
