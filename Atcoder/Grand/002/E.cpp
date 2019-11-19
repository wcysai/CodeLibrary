#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,a[MAXN];
bool candetermine(int x,int y)
{
    return (a[x+1]<y+1);
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    sort(a+1,a+N+1,greater<int>());
    int id=-1;
    for(int i=1;i<=N;i++)
    {
        if(candetermine(i,i))
        {
            int cnt1=(a[i]-i),cnt2=0;
            for(int j=i+1;j<=N;j++) if(a[j]>=i) cnt2++;
            if(cnt1%2==0&&cnt2%2==0) puts("Second"); else puts("First");
            return 0;
        }
    }
    return 0;
}
