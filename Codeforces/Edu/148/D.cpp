#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int res[MAXN];
int b[MAXN],c[MAXN];
ll sumb[MAXN],sumc[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int val=INF;
    for(int i=1;i<=n;i++){
        val=min(val+1,a[i]+1);
        res[i]=min(val,i==n?INF:a[i+1]);
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i]+(n+1)-i;
        c[i]=b[i]-1;
    }
    sort(b+1,b+n+1);
    sort(c+1,c+n);
    sumb[n+1]=sumc[n]=0;
    for(int i=n;i>=1;i--){
        sumb[i]=sumb[i+1]+b[i];
    }
    for(int i=n-1;i>=1;i--){
        sumc[i]=sumc[i+1]+c[i];
    }
    for(int i=1;i<=q;i++){
        int k; scanf("%d",&k);
        if(n==1){
            if(k&1) printf("%d ",a[1]+(k+1)/2);
            else printf("%d ",a[1]-k/2);
            continue;
        }
        if(k<=n) printf("%d ",res[k]);
        else if((k-n)&1){
            int rem=(k-(n-1))/2;
            int l=0,r=n;
            while(r-l>1){
                int mid=(l+r)/2;
                ll need=sumc[mid]-1LL*(n-mid)*c[mid];
                if(c[mid]+k-(n-1)<=a[n]) need+=a[n]-(c[mid]+k-(n-1));
                if(rem<=need) l=mid; else r=mid; 
            }
            if(r==n) {printf("%d ",k-(n-1)+c[1]); continue;}
            ll need=sumc[r]-1LL*(n-r)*c[r];
            int len=n-r,now=c[r]+k-(n-1);
          //  printf("r=%d c=%d a=%d sum=%d need=%lld len=%d\n",r,c[r],a[n],c[r]+k-(n-1),need,len);
            if(c[r]+k-(n-1)<=a[n]) {need+=a[n]-(c[r]+(k-(n-1))); len++;}
            else if(need+1LL*(c[r]+k-(n-1)-a[n])*len<rem) {need+=1LL*(c[r]+k-(n-1)-a[n])*len; len++; now=a[n];}
            if(r==1) printf("%lld ",min(1LL*c[n],now-(rem-need+len-1)/(len)));
            else printf("%lld ",min(1LL*c[n],k-(n-1)+1LL*c[1]));
        }
        else{
            int rem=(k-n)/2;
            int l=0,r=n;
            while(r-l>1){
                int mid=(l+r)/2;
                ll need=sumb[mid]-1LL*(n+1-mid)*b[mid];
                if(rem<=need) l=mid; else r=mid; 
            }
            ll need=sumb[r]-1LL*(n+1-r)*b[r];
            //printf("r=%d need=%lld\n",r,need);
            if(r==1) printf("%lld ",k-n+b[r]-(rem-need+n-r)/(n-r+1));
            else printf("%lld ",k-n+1LL*b[1]);
        }
    }
    printf("\n");
    return 0;
}

