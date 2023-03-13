#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
string a,b;
int dp[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        cin>>a>>b;
        n=(int)a.size(); m=(int)b.size();
        if(a[0]==b[0]){
            cout<<"YES"<<endl;
            printf("%c%c\n",a[0],'*');
        }
        else if(a[n-1]==b[m-1]){
            cout<<"YES"<<endl;
            printf("%c%c\n",'*',a[n-1]);
        }
        else{
            bool f=false;
            for(int i=0;i<n-1;i++)
            {
                if(f) break;
                for(int j=0;j<m-1;j++)
                    if(a[i]==b[j]&&a[i+1]==b[j+1]){
                        f=true; 
                        cout<<"YES"<<endl;
                        printf("*%c%c*\n",a[i],a[i+1]);
                        break;
                    }
            }
            if(!f) puts("NO");
        }
    }
    return 0;
}

