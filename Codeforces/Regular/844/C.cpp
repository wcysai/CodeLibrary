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
int t,n,k,a[MAXN];
int cnt[MAXN];
char str[MAXN];
char ss[MAXN];
vector<int> v;
bool cmp(int x,int y){
    return cnt[x]>cnt[y];
}
int calc(int x){
    int gt=0,sum=0;
    for(int i=0;i<n/x;i++) 
    {
        sum+=cnt[v[i]];
        if(cnt[v[i]]>x) gt+=cnt[v[i]]-x;
    }
    return (n-sum)+gt;
}
void build(int x){
    for(int i=1;i<=n;i++) ss[i]='0';
    for(int i=0;i<n/x;i++){
        int same=min(cnt[v[i]],x);
        int c=0;
        for(int j=1;j<=n;j++){
            if(str[j]=='a'+v[i]){
                c++;
                ss[j]=str[j];
            }
            if(c==same) break;
        }
    }
    for(int i=0;i<n/x;i++)
    {
        int same=min(cnt[v[i]],x);
        int c=x-same;
        for(int j=1;j<=n;j++){
            if(!c) break;
            if(ss[j]=='0'){
                ss[j]='a'+v[i];
                c--;
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    for(int i=0;i<26;i++) v.push_back(i);
    while(t--){
        scanf("%d",&n);
        scanf("%s",str+1);
        for(int i=0;i<26;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) cnt[str[i]-'a']++;
        sort(v.begin(),v.end(),cmp);
        int need=n+1,id=0;
        for(int i=1;i<=n;i++){
            if(n%i) continue;
            if(n/i>26) continue;
            int x=calc(i);
            if(x<need) {need=x; id=i;}
        }
        build(id);
        printf("%d\n",need);
        for(int i=1;i<=n;i++) printf("%c",ss[i]);
        printf("\n");
    }
    return 0;
}

