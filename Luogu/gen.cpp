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
int T,q;
//mt19937 wcy(time(NULL));
int main()
{
    T=150000; q=300000;
    printf("%d %d\n",T,q);
    for(int i=1;i<=T;i++){
        printf("ADD 1 1\n");
    }
    for(int i=T;i>=1;i--){
        printf("DEL 1 1\n");
    }
    return 0;
}

