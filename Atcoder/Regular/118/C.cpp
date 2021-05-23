#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> v1,v2,v3;
int a[MAXN];
int main()
{
    for(int i=1;i<=10000;i++)
    {
        if(i%6==0) v1.push_back(i);
        else if(i%10==0) v2.push_back(i);
        else if(i%15==0) v3.push_back(i);
    }
    a[1]=v1.back(); v1.pop_back();
    a[2]=v2.back(); v2.pop_back();
    a[3]=v3.back(); v3.pop_back();
    int n;
    scanf("%d",&n);
    for(int i=4;i<=n;i++)
    {
        if(v1.size()) {a[i]=v1.back(); v1.pop_back();}
        else if(v2.size()) {a[i]=v2.back(); v2.pop_back();}
        else {a[i]=v3.back(); v3.pop_back();}
    }
    for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}