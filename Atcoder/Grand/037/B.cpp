#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
int ans;
int cnt[7];
/*
1: R
2: G
3: B
4: RG
5: RB
6: GB
*/
int main()
{
    scanf("%d",&n);
    cin>>str;
    ans=1;
    cnt[0]=n;
    for(int i=0;i<3*n;i++)
    {
        if(str[i]=='R')
        {
            if(cnt[6]>0) {ans=1LL*cnt[6]*ans%MOD; cnt[6]--;}
            else if(cnt[2]) {ans=1LL*ans*cnt[2]%MOD; cnt[2]--; cnt[4]++;}
            else if(cnt[3]) {ans=1LL*ans*cnt[3]%MOD; cnt[3]--; cnt[5]++; }
            else {ans=1LL*ans*cnt[0]%MOD; cnt[0]--; cnt[1]++;}
        }
        else if(str[i]=='B')
        {
            if(cnt[4]>0) {ans=1LL*cnt[4]*ans%MOD; cnt[4]--;}
            else if(cnt[1]) {ans=1LL*ans*cnt[1]%MOD; cnt[1]--; cnt[5]++;}
            else if(cnt[2]) {ans=1LL*ans*cnt[2]%MOD; cnt[2]--; cnt[6]++; }
            else {ans=1LL*ans*cnt[0]%MOD; cnt[0]--; cnt[3]++;}
        }
        else
        {
            if(cnt[5]>0) {ans=1LL*cnt[5]*ans%MOD; cnt[5]--;}
            else if(cnt[1]) {ans=1LL*ans*cnt[1]%MOD; cnt[1]--; cnt[4]++;}
            else if(cnt[3]) {ans=1LL*ans*cnt[3]%MOD; cnt[3]--; cnt[6]++; }
            else {ans=1LL*ans*cnt[0]%MOD; cnt[0]--; cnt[2]++;}
        }
    }
    printf("%d\n",ans);
    return 0;
}
