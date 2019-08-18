#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
char str[MAXN];
int cnt[10],tmp[10];
int ans[MAXN],res[MAXN];
int main()
{
    freopen("done.in","r",stdin);
    freopen("done.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str+1);
        n=strlen(str+1);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) cnt[(int)(str[i]-'0')]++;
        for(int i=0;i<10;i++) tmp[i]=cnt[i];
        ans[0]=2;
        n/=2;
        for(int x=0;x<10;x++)
            for(int y=x;y<10;y++)
            {
                for(int i=0;i<=n;i++) res[i]=0;
                if(!cnt[x]||!cnt[y]) continue;
                if(x==y&&cnt[x]<2) continue;
                cnt[x]--; cnt[y]--;
                int tot=1;
                for(int i=0;i<=4;i++)
                {
                    int val=min(cnt[i],cnt[9-i]);
                    for(int j=tot;j<=tot+val-1;j++) res[j]=9;
                    tot+=val;
                    cnt[i]-=val; cnt[9-i]-=val;
                }
                res[0]=0;
                res[tot]=x+y; tot++;
                int f=0,now;
                for(int i=0;i<=9;i++)
                {
                    if(x+y>9) now=i; else now=9-i;
                    for(int j=0;j<cnt[now];j++)
                    {
                        res[tot]+=now;
                        if(f) ++tot;
                        f^=1;
                    }
                }
                for(int i=n;i>=1;i--)
                {
                    if(res[i]>=10)
                    {
                        res[i]-=10;
                        res[i-1]++;
                    }
                }
                if(res[0]) res[0]--;
                else
                {
                    for(int i=1;i<=n;i++) res[i]=9-res[i];
                    res[n]++;
                    for(int i=n;i>=1;i--)
                    {
                        if(res[i]>=10)
                        {
                            res[i]-=10;
                            res[i-1]++;
                        }
                        else break;
                    }
                }
                int cur=0;
                while(ans[cur]==res[cur]&&cur<n) cur++;
                if(cur<=n&&res[cur]<ans[cur])
                {
                    for(int i=0;i<=n;i++) ans[i]=res[i];
                }
                for(int i=0;i<10;i++) cnt[i]=tmp[i];
            }
        bool zero=true;
        for(int i=0;i<=n;i++)
        {
            if(ans[i]) zero=false;
            if(!zero) printf("%d",ans[i]);
        }
        if(zero) puts("0"); else puts("");
    }
    return 0;
}
