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
int n,k,a[MAXN];
char s[MAXN];
vector<int> A,B;
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n+1;i++) if(s[i]=='A') A.push_back(i); else B.push_back(i);
    for(int i=1;i<=n;i++){
        int x=(i+1)/2,y=i-x;
        if(x>=(int)B.size()) printf("Alice\n");
        else if(y>=(int)A.size()) printf("Bob\n");
        else{
            int posx=B[x-1],posy=A[y-1];
            if(max(posx,posy)==i-1){
                if(s[i]=='A') printf("Alice\n");
                else printf("Bob\n");
            }
            else{
                if(posx>posy) printf("Alice\n");
                else printf("Bob\n");
            }
        }
    }
    return 0;
}

