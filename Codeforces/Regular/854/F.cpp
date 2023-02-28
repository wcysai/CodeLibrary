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
int t,n,b,k1,k2,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&b,&k1,&k2);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        ll ans=0,sum=0;
        multiset<int> s1,s2,s3;
        for(int i=1;i<=k2;i++){
            ans+=min(a[i],b); 
            s1.insert(a[i]);
        }
        for(int i=1;i<=n;i++) sum+=a[i];
        for(int i=k2+1;i<=n;i++) s2.insert(a[i]);
        for(int i=0;i<k1;i++){
            int x=-INF,y=-INF,z=-INF,w=-INF;
            if(s1.size()){
                int val=*(--s1.end());
                x=(val/2)+min((val+1)/2,b)-min(val,b);
            }
            if(s2.size()){
                int val=*(--s2.end());
                y=val/2;
            }
            if(s1.size()&&s2.size()){
                int val1=*(--s1.end()),val2=*(--s2.end());
                int val3=*(s1.begin());
                z=max(val3/2-min(val3,b),(val1/2)-min(val1,b))+min(val2,b);
            }
            if(s1.size()&&s3.size()){
                int val1=*(--s1.end()),val2=*(--s3.end());
                int val3=*(s1.begin());
                w=max(val3/2-min(val3,b),(val1/2)-min(val1,b))+min(val2,b);
            }
            if(x<=0&&y<=0&&z<=0&&w<=0) break;
            if(x>=y&&x>=z&&x>=w){
                ans+=x;
                s1.erase(--s1.end());
            }
            else if(y>=z&&y>=x&&y>=w){
                ans+=y; s3.insert((*(--s2.end())+1)/2);
                s2.erase(--s2.end()); 
            }
            else if(z>=x&&z>=y&&z>=w){
                ans+=z;
                int val1=*(--s1.end()),val2=*(--s2.end());
                int val3=*(s1.begin());
                if(z==val1/2-min(val1,b)+min(val2,b)){
                    s1.erase(--s1.end()); s2.erase(--s2.end());
                    s1.insert(val2); s3.insert((val1+1)/2);
                }
                else{
                    s1.erase(s1.begin()); s2.erase(--s2.end());
                    s1.insert(val2); s3.insert((val3+1)/2);
                }
            }
            else{
                ans+=w;
                int val1=*(--s1.end()),val2=*(--s3.end()),val3=*s1.begin();
                if(w==val1/2-min(val1,b)+min(val2,b)){
                    s1.erase(--s1.end()); s3.erase(--s3.end());
                    s3.insert((val1+1)/2);
                }
                else{
                    s1.erase(s1.begin()); s3.erase(--s3.end());
                    s3.insert((val3+1)/2);
                }
            }
        }
        printf("%lld\n",sum-ans);
    }
    return 0;
}

