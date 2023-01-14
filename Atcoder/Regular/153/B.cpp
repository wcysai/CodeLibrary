#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
vector<int> x,y;
string str[MAXN];
string tmp[MAXN];
int a[MAXN],b[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) cin>>str[i];
    scanf("%d",&q);
    int rev=0,shiftx=0,shifty=0;
    for(int i=0;i<q;i++){
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        if(!rev){
            shiftx=(shiftx+n-aa)%n;
            shifty=(shifty+m-bb)%m;
        }
        else{
            shiftx=(shiftx+aa)%n;
            shifty=(shifty+bb)%m;
        }
        rev^=1;
    }
    if(!rev){
        for(int i=0;i<n;i++) a[(shiftx+i)%n]=i;
        for(int j=0;j<m;j++) b[(shifty+j)%m]=j;
    }
    else{
        for(int i=0;i<n;i++) a[(2*n-1-i-shiftx)%n]=i;
        for(int j=0;j<m;j++) b[(2*m-1-j-shifty)%m]=j;
    }
    for(int i=0;i<n;i++) tmp[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            tmp[i][j]=str[a[i]][b[j]];
    for(int i=0;i<n;i++) cout<<tmp[i]<<endl;
    return 0;
}

