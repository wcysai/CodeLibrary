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
int a,b,c,d;
int ans[100000];
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int cnt0=-1,cnt1=-1;
    int p=(int)sqrt(a*2);
    for(int i=max(0,p-10);i<=p+10;i++) if(i*(i-1)==a*2) {cnt0=i; break;}
    p=sqrt(d*2);
    for(int i=max(0,p-10);i<=p+10;i++) if(i*(i-1)==d*2) {cnt1=i; break;}
    if(cnt0==-1||cnt1==-1) {puts("impossible"); return 0;}
    if(a==0&&d==0)
    {
        if(b==1&&c==0) puts("01");
        else if(b==0&&c==1) puts("10");
        else if(b==0&&c==0) puts("0");
        else puts("impossible");
        return 0;
    }
    else if(a==0)
    {
        if(b==0&&c==0)
        {
            for(int i=0;i<cnt1;i++) printf("1");
        }
        else if(b+c!=cnt1) puts("impossible");
        else
        {
            for(int i=0;i<c;i++) printf("1");
            printf("0");
            for(int i=0;i<b;i++) printf("1");
            puts("");
        }
        return 0;
    }
    else if(d==0)
    {
        if(b==0&&c==0)
        {
            for(int i=0;i<cnt0;i++) printf("0");
        }
        else if(b+c!=cnt0) puts("impossible");
        else
        {
            for(int i=0;i<b;i++) printf("0");
            printf("1");
            for(int i=0;i<c;i++) printf("0");
            puts("");
        }
        return 0;
    }
    else
    {
        if(b+c!=1LL*cnt0*cnt1) puts("impossible");
        else
        {
            for(int i=cnt0;i>=1;i--)
            {
                ans[i]=b/i;
                cnt1-=ans[i];
                b-=ans[i]*i;
            }
            for(int j=0;j<cnt1;j++) printf("1");
            for(int i=1;i<=cnt0;i++)
            {
                printf("0");
                for(int j=0;j<ans[i];j++) printf("1");
            }
            puts("");
        }
    }
    return 0;
}

