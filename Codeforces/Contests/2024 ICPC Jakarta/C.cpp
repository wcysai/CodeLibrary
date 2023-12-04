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
int n,k,a[MAXN];
int main(){
    for(int mask=1;mask<(1<<9);mask++){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int id=i*3+j;
                if(mask&(1<<id)) printf("1"); else printf("0");
            }
            printf("\n");
        }
    }
    return 0;
}

