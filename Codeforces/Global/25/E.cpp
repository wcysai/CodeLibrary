#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
char str[MAXN];
bool pre[MAXN],suf[MAXN];
void manacher(char str[],int len[],int n)
{
    len[0]=1;
    for(int i=1,j=0;i<(n<<1)-1;++i)
    {
        int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1&&q+len[i]<n&&str[p-len[i]]==str[q+len[i]])
            ++len[i];
        if(q+len[i]-1>r)
            j=i;
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        cin>>str;
        n=strlen(str);
        bool f=true;
        for(int i=0;i<n;i++) if(str[i]!=str[n-1-i]) {f=false; break;}
        if(!f) {
            puts("YES");
            puts("1");
            printf("%s\n",str); continue;
        }
        for(int i=0;i<=n;i++) pre[i]=suf[i]=false;
        manacher(str,a,n);
        for(int i=0;i<2*n-1;i++){
            if(a[i]==i/2+1) pre[i+1]=true;
            if(a[i]==(2*n-2-i)/2+1) suf[(2*n-2-i)+1]=true;
        }
        f=false;
        for(int i=2;i<n;i++){
            if(!pre[i]&&!suf[n-i]){
                f=true;
                printf("YES\n");
                puts("2");
                for(int j=0;j<i;j++) printf("%c",str[j]); 
                printf(" ");
                for(int j=i;j<n;j++) printf("%c",str[j]); 
                printf("\n");
                break;
            }
        }
        if(!f) puts("NO");
    }
    return 0;
}

