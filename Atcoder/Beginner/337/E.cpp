#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> v[MAXN];
int main(){
    scanf("%d",&n);
    int x=1,res=2;
    while(res<n){
        x++; res*=2;
    }
    printf("%d\n",x);
    fflush(stdout);
    for(int i=0;i<n;i++){
        for(int j=0;j<x;j++){
            if(i&(1<<j)) v[j].push_back(i+1);
        }
    }
    for(int i=0;i<x;i++){
        printf("%d",(int)v[i].size());
        for(auto z:v[i]) printf(" %d",z);
        printf("\n");
        fflush(stdout);
    }
    string str;
    cin>>str;
    int s=0;
    for(int i=0;i<x;i++) if(str[i]=='1') s+=(1<<i);
    printf("%d\n",s+1);
    fflush(stdout);
    return 0;
}

