#include<bits/stdc++.h>
#define MAXN 55
#define MAXK 35
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
int T,P,S,K,N;
int A[MAXK][MAXN];
pair<int,int> b[MAXN];
vector<int> ans;
vector<int> perm;
int rotated_amount;
bool bad[MAXN];
bool cmp(int x,int y)
{
    return b[x]<b[y];
}
void rotate_right(int num)
{
    int id=(N-1-num)%(N-1);
    int base=1;
    for(int i=0;i<4;i++)
    {
        int k=(num/base)%3;
        for(int j=0;j<k;j++) ans.push_back(i);
        base*=3;
    }
    rotate(perm.begin(),perm.begin()+id,(--perm.end()));
    rotated_amount=(rotated_amount+num)%(N-1);
}
void check_bad()
{
    memset(bad,false,sizeof(bad));
    for(int i=0;i<N-1;i++)
    {
        int pos=(i-rotated_amount+N-1)%(N-1);
        if(pos!=perm[i]) bad[i]=true;
    }
}
void go_swap(int pos)
{
    int need=(N-2-pos);
    rotate_right(need);
    ans.push_back(4);
    swap(perm[N-2],perm[N-1]);
}
void solve_permutation()
{
    ans.clear(); rotated_amount=0;
    while(true)
    {
        if(perm[N-1]!=N-1)
        {
            int pos=(perm[N-1]+rotated_amount)%(N-1);
            go_swap(pos);
        }
        else
        {
            check_bad();
            bool f=false;
            for(int i=N-2;i>=0;i--)
            {
                if(bad[i])
                {
                    f=true;
                    go_swap(i);
                    break;
                }
            }
            if(!f) break;
        }
    }
    int need=(N-1-rotated_amount)%(N-1);
    rotate_right(need);
}
void construct_rotate(int num)
{
    num%=(N-1);
    vector<int> tmp;
    for(int i=0;i<N;i++) tmp.push_back(i);
    int id=N-1-num;
    rotate(tmp.begin(),tmp.begin()+id,(--tmp.end()));
    for(auto x:tmp) printf("%d ",x+1);
    puts("");
}
void construct_swap()
{
    vector<int> tmp;
    for(int i=0;i<N;i++) tmp.push_back(i);
    swap(tmp[N-1],tmp[N-2]);
    for(auto x:tmp) printf("%d ",x+1);
    puts("");
}
int main()
{
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        scanf("%d%d%d%d",&P,&S,&K,&N);
        for(int i=0;i<K;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&A[i][j]);
        printf("Case #%d:\n",_);
        printf("%d\n",5);
        construct_rotate(1); construct_rotate(3); construct_rotate(9); construct_rotate(27);
        construct_swap();
        for(int i=0;i<K;i++)
        {
            perm.clear(); perm.resize(N);
            for(int j=0;j<N;j++) b[j]=make_pair(A[i][j],j);
            sort(b,b+N);
            for(int j=0;j<N;j++) perm[b[j].second]=j;
            solve_permutation();
            printf("%d",(int)ans.size());
            for(auto x:ans) printf(" %d",x+1);
            puts("");
        }
    }
    return 0;
}
