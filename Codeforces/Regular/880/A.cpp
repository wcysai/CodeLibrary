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
int t,A,B,C;
int p10[10];
ll k;
vector<pair<string,int> > v[7];
int main()
{
    p10[0]=1;
    for(int i=1;i<=9;i++) p10[i]=p10[i-1]*10;
    for(int A=1;A<=6;A++){
        for(int i=p10[A-1];i<=p10[A]-1;i++){
            string str="";
            int tmp=i;
            while(tmp){
                str+=(char)('0'+tmp%10); tmp/=10;
            }
            reverse(str.begin(),str.end());
            v[A].push_back(make_pair(str,i));
        }
        sort(v[A].begin(),v[A].end());
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&A,&B,&C);
        scanf("%lld",&k);
        if(max(A,B)>C) {puts("-1"); continue;}
        if(max(A,B)+1<C){
            puts("-1"); continue;
        }
        bool f=false;
        for(int i=0;i<(int)v[A].size();i++){
            int l=max(p10[B-1],p10[C-1]-v[A][i].S);
            int r=min(p10[B]-1,p10[C]-1-v[A][i].S);
            if(l>r) continue;
            if(r-l+1>=k){
                printf("%d + %d = %d\n",v[A][i].S,l+k-1,v[A][i].S+l+k-1);
                f=true; break;
            }
            else{
                k-=(r-l+1);
            }
        }
        if(!f) puts("-1");
    }
    return 0;
}

