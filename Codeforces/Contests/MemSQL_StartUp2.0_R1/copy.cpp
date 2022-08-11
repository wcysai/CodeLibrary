#include <bits/stdc++.h>
using namespace std; 
namespace IO {
    void setIO(string s) {
        string in=s+".in"; 
        freopen(in.c_str(),"r",stdin); 
    } 
}; 
#define ll long long 
const int maxn=600004;   
const ll mod=1000000007;    
int last,tot; 
int ch[maxn][30],f[maxn],len[maxn],n[4],rk[maxn],tax[maxn];     
ll answer[maxn], cnt[maxn][4];    
char A[maxn];       
void extend(int c,int i) {          
    int p=last;   
    if(ch[p][c]) {       
        int q=ch[p][c]; 
        if(len[q]==len[p]+1) last=q;   
        else {
            int nq=++tot;                  
            last=nq,len[nq]=len[p]+1;    
            memcpy(ch[nq],ch[q],sizeof(ch[q]));   
            f[nq]=f[q],f[q]=nq;       
            while(p&&ch[p][c]==q) ch[p][c]=nq,p=f[p];  
        }
    }
    else {
        int np=++tot;       
        len[np]=len[p]+1,last=np; 
        while(p&&!ch[p][c]) ch[p][c]=np,p=f[p]; 
        if(!p) f[np]=1; 
        else {
            int q=ch[p][c];    
            if(len[q]==len[p]+1) f[np]=q; 
            else {
                int nq=++tot;    
                len[nq]=len[p]+1;    
                memcpy(ch[nq],ch[q],sizeof(ch[q]));   
                f[nq]=f[q],f[np]=f[q]=nq;       
                while(p&&ch[p][c]==q) ch[p][c]=nq,p=f[p];      
            }
        }    
    }
    ++cnt[last][i];  
}
int main() { 
    // IO::setIO("input"); 
    last=tot=1; 
    int i,j; 
    for(i=0;i<3;++i) {
        scanf("%s",A+1), n[i]=strlen(A+1),last=1;     
        for(j=1;j<=n[i];++j) extend(A[j]-'a',i);          
    }          
    printf("tot=%d\n",tot);
    for(i=1;i<=tot;++i) ++tax[len[i]];         
    for(i=1;i<=tot;++i) tax[i]+=tax[i-1]; 
    for(i=1;i<=tot;++i) rk[tax[len[i]]--]=i;     
    for(i=tot;i>=2;--i) {
        int cur=rk[i];    
        for(j=0;j<3;++j) cnt[f[cur]][j]+=cnt[cur][j];      
        ll now=cnt[cur][0]*cnt[cur][1]%mod*cnt[cur][2]%mod;     
        answer[len[f[cur]]+1]=(answer[len[f[cur]]+1]+now)%mod;   
        answer[len[cur]+1]=(answer[len[cur]+1]-now+mod)%mod;       
    }
    for(i=1;i<=tot;++i) answer[i]+=answer[i-1],answer[i]%=mod; 
    for(i=1;i<=min(n[0],min(n[1],n[2]));++i) printf("%lld ",answer[i]); 
    return 0; 
}
