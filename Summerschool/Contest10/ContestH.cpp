#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int fa[MAXN],n,k,t,x,ans;
bool f[MAXN];
class fastIO{
private:
    char s[1000010];
    int cnt,size;
    bool stop;
    FILE *fin;
    inline void read(){
        if(cnt>=size){
            size=fread(s,1,1,fin);
            cnt=0;
            if(size<=0)
                stop=1;
        }
    }
public:
    fastIO(FILE *f){
        fin=f;
        size=0;
        cnt=0;
        stop=0;
        read();
    }
    inline void read(int& x){
        x=0;
        while((s[cnt]==' '||s[cnt]=='\n')){
            cnt++;
            read();
        }
        while(s[cnt]!=' '&&s[cnt]!='\n'&&!stop){
            x=x*10+s[cnt]-'0';
            cnt++;
            read();
        }
    }
    inline void read(ll& x){
        x=0;
        while((s[cnt]==' '||s[cnt]=='\n')){
            cnt++;
            read();
        }
        while(s[cnt]!=' '&&s[cnt]!='\n'&&!stop){
            x=x*10+s[cnt]-'0';
            cnt++;
            read();
        }
    }
    inline int read(char x[]){
        int len=0;
        while((s[cnt]==' '||s[cnt]=='\n')){
            cnt++;
            read();
        }
        while(s[cnt]!=' '&&s[cnt]!='\n'&&!stop){
            x[len++]=s[cnt++];
            read();
        }
        x[len]='\0';
        return len;
    }
};
int main()
{
    fastIO fin(stdin);
    fin.read(t);
    while(t--)
    {
        memset(f,false,sizeof(f));
        fin.read(n);
        fin.read(k);
        for(int i=1;i<n;i++)
            fin.read(fa[i+1]);
        ans=0;
        for(int i=n;i>=1;i--)
            if(f[i]) ans++; else f[fa[i]]=true;
        int m=min(k/2,ans);
        printf("%d\n",k-m);
    }
    return 0;
}
