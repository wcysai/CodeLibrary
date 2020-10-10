#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long int;
typedef pair<int,int> P;
int n;
vector<int> v1,v2;
bool has[6*MAXN];
int id[6*MAXN];
int main()
{
    scanf("%d",&n);
    memset(has,false,sizeof(has));
    for(int i=1;i<=3*n;i++) 
    {
        int x;
        scanf("%d",&x);
        v1.push_back(x);
        has[x]=true;
    }
    for(int i=1;i<=6*n;i++) if(!has[i]) v2.push_back(i);
    for(int i=0;i<(int)v1.size();i+=3)
        id[v1[i]]=id[v1[i+1]]=id[v1[i+2]]=i/3+1;
    for(int i=0;i<(int)v1.size();i+=3)
        id[v2[i]]=id[v2[i+1]]=id[v2[i+2]]=n+i/3+1;
        
}