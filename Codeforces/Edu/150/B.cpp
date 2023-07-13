#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,q;
vector<int> a,b;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&q);
        a.clear(); b.clear();
        for(int i=0;i<q;i++){
            int x;
            scanf("%d",&x);
            if(b.size()){
                if(x>=b.back()&&x<=a[0]){
                    b.push_back(x);
                    printf("1");
                }
                else printf("0");
            }
            else{
                if(!a.size()||x>=a.back()){
                    a.push_back(x);
                    printf("1");
                }
                else if(x<=a[0]){
                    b.push_back(x);
                    printf("1");
                }
                else printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}

