#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[MAXN];
int n,k,res;
vector<int> consec;
int main()
{
    scanf("%s",str+1);
    scanf("%d",&k);
    n=strlen(str+1);
    bool f=true;
    for(int i=2;i<=n;i++)
    {
        if(str[i]!=str[i-1])
        {
            f=false;
            break;
        }
    }
    if(f)
    {
        printf("%lld\n",1LL*n*k/2);
        return 0;
    }
    int cnt=1;
    res=0;
    for(int i=2;i<=n;i++)
    {
        if(str[i]==str[i-1]) cnt++;
        else
        {
            consec.push_back(cnt);
            res+=cnt/2;
            cnt=1;
        }
    }
    consec.push_back(cnt);
    res+=cnt/2;
    if(str[1]!=str[n]) printf("%lld\n",1LL*res*k);
    else
    {
        ll ans=1LL*res*k;
        ans-=1LL*(k-1)*(consec[0]/2+consec.back()/2);
        ans+=1LL*(k-1)*((consec[0]+consec.back())/2);
        printf("%lld\n",ans);
    }
    return 0;
}
