#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,M,cnt;
vector<int> v,a,b;
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        int x;
        scanf("%d",&x);
        if(x&1) cnt++;
        v.push_back(x);
    }
    if(cnt>2) {puts("Impossible"); return 0;}
    int odd1=-1,odd2=-1;
    for(int i=0;i<M;i++)
    {
        if(v[i]&1) {if(odd1==-1) odd1=v[i]; else odd2=v[i];}
        else a.push_back(v[i]);
    }
    if(odd1!=-1) a.push_back(odd1);
    if(odd2!=-1) {reverse(a.begin(),a.end()); a.push_back(odd2); reverse(a.begin(),a.end());}
    int sum=0;
    for(int i=0;i<(int)a.size();i++)
    {
        int x=a[i];
        if(i==0) x--; else if(i==(int)a.size()-1) x++;
        sum+=x;
        if(x) b.push_back(x);
    }
    if(sum<N) b.push_back(1);
    for(auto x:a) printf("%d ",x);
    puts("");
    printf("%d\n",(int)b.size());
    for(auto x:b) printf("%d ",x);
    puts("");
    return 0;
}
