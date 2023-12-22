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
int T,n,k,a[MAXN];
bool a_win(vector<int> &v){
    for(int i=0;i<n-1;i++){
        if(v[i]!=-1&&v[i+1]!=-1&&max(v[i]-v[i+1],v[i+1]-v[i])==1) return true;
    }
    return false;
}
bool a_can_win(vector<int> &v){
    if(a_win(v)) return true;
    vector<bool> used(n,false);
    for(int i=0;i<(int)v.size();i++) if(v[i]!=-1) used[v[i]]=true;
    for(int i=0;i<n-1;i++){
        if(v[i]==-1&&v[i+1]!=-1&&v[i+1]!=0&&!used[v[i+1]-1]) return true;
        if(v[i]==-1&&v[i+1]!=-1&&v[i+1]!=n-1&&!used[v[i+1]+1]) return true;
        if(v[i+1]==-1&&v[i]!=-1&&v[i]!=0&&!used[v[i]-1]) return true;
        if(v[i+1]==-1&&v[i]!=-1&&v[i]!=n-1&&!used[v[i]+1]) return true;
    }
    return false;
}
bool check_amove_bwin(vector<int> &v){
    if(a_can_win(v)) return false;
    vector<bool> used(n,false);
    vector<int> valid_pos,valid_num;
    for(int i=0;i<n;i++){
        if(v[i]!=-1) used[v[i]]=true;
        else valid_pos.push_back(i);
    }
    for(int i=0;i<n;i++) if(!used[i]) valid_num.push_back(i);
    if(valid_pos.size()<2) return true;
    if(valid_pos.size()==2){
        assert(valid_num.size()==2);
        if(valid_pos[1]==valid_pos[0]+1&&valid_num[1]==valid_num[0]+1) return false;
        else return true;
    }
    bool f1=false,f2=false;
    for(int i=0;i<(int)valid_pos.size()-2;i++){
        if(valid_pos[i+1]==valid_pos[i]+1&&valid_pos[i+2]==valid_pos[i+1]+1) f1=true;
    }
    for(int i=0;i<(int)valid_num.size()-2;i++){
        if(valid_num[i+1]==valid_num[i]+1&&valid_num[i+2]==valid_num[i+1]+1) f2=true;
    }
    if(f1&&f2) return false; 
    if(valid_pos.size()&1){
        int sz=(int)valid_pos.size();
        int cnt1=0,cnt2=0;
        for(int i=0;i<(int)valid_pos.size()-1;i++){
            if(valid_pos[i+1]==valid_pos[i]+1){
                cnt1++; i++;
            }
        }
        for(int i=0;i<(int)valid_num.size()-1;i++){
            if(valid_num[i+1]==valid_num[i]+1){
                cnt2++; i++;
            }
        }
        if(2*(cnt1+cnt2)>sz) return false;
        else return true;
    }
    else return true;
}
bool check_bmove_bwin(vector<int> &v){
    if(a_win(v)) return false;
    vector<int> tmp=v;
    vector<bool> used(n,false);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]!=-1) used[v[i]]=true; else cnt++;
    }
    if(cnt==0) return true;
    for(int i=0;i<n;i++){
        if(tmp[i]!=-1) continue;
        for(int j=0;j<n;j++){
            if(used[j]) continue;
            tmp[i]=j; if(check_amove_bwin(tmp)) return true;
            tmp[i]=-1;
        }
    }
    return false;
}
int check_state(vector<int> &v,int move){//0: awin,1: bwin
    if(!move){//a move
        if(check_amove_bwin(v)) return 1; else return 0;
    }
    else{
        if(check_bmove_bwin(v)) return 1; else return 0;
    }
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        vector<int> v(n,-1);
        int st=check_state(v,0);
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            int m,c;
            scanf("%d%d",&m,&c);
            m--; c--;
            v[m]=c;
            int nst=check_state(v,i&1);
            if(st!=nst){
                if(i&1) a++; else b++;
            }
            //printf("i=%d st=%d nst=%d\n",i,st,nst);
            st=nst;
        }
        printf("Case #%d: %d %d\n",t,a,b);
    }
    return 0;
}

