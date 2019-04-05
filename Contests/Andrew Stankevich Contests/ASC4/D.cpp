#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,m;
char str[MAXN],ch;
int type;
const char* cond[3]=
{
    " arbitary",
    "<=0",
    ">=0"
};
const char* rest[3]=
{
    "=",
    "<=",
    ">="
};
void transpose(mat &A)
{
    int n=(int)A.size(),m=(int)A[0].size();
    mat B(m,vec(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[j][i];
    A=B;
}
void getval(vector<int> &v)
{
    scanf(" ");
    ch=getchar();
    if(ch!='0')
    {
        if(ch!='+'&&ch!='-')
        {
            ungetc(ch,stdin);
            ch='+';
        }
        do
        {
            int c=1,x;
            scanf("%d",&c);
            getchar();
            scanf("%d",&x);
            v[x-1]+=(ch=='+')?c:-c;
            ch=getchar();
            if(ch!='+'&&ch!='-')
            {
                ungetc(ch,stdin);
                break;
            }
        }while(true);
    }
}
void printval(vector<int> &v,int n)
{
    bool f=false;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0) continue;
        if(v[i]==1)
        {
            if(f) putchar('+');
        }
        else if(v[i]==-1) putchar('-');
        else if(f) printf("%+d",v[i]);
        else printf("%d",v[i]);
        printf("y%d",i+1);
        f=true;
    }
    if(!f) putchar('0');
}
int main()
{
    freopen("dual.in","r",stdin);
    freopen("dual.out","w",stdout);
    scanf("%d%d",&n,&m);
    vec goal(n);
    vec cont(n);
    mat coef(m,vec(n));
    mat cont2(m,vec(2));
    scanf("%s",str);
    if(str[1]=='i') type=0; else type=1;
    getval(goal);
    scanf(" with");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf(" x%d%[^\n]",&x,str);
        if(str[0]==' ') cont[i]=0;
        else if(str[0]=='<') cont[i]=1;
        else cont[i]=2;
    }
    scanf(" under");
    for(int i=0;i<m;i++)
    {
        getval(coef[i]);
        ch=getchar();
        if(ch=='=') cont2[i][0]=0;
        else if(ch=='<') {cont2[i][0]=1; getchar();}
        else {cont2[i][0]=2; getchar();}
        scanf("%d",&cont2[i][1]);
    }
    printf("%d %d\n",m,n);
    transpose(coef);transpose(cont2);
    if(type==0) printf("max "); else printf("min ");
    printval(cont2[1],m);
    if(type==0)
    {
        for(int i=0;i<n;i++) cont[i]=cont[i]?3-cont[i]:0;
    }
    else 
    {
        for(int i=0;i<m;i++) cont2[0][i]=cont2[0][i]?3-cont2[0][i]:0;
    }
    printf("\nwith\n");
    for(int i=0;i<m;i++) printf("y%d%s\n",i+1,cond[cont2[0][i]]);
    printf("under\n");
    for(int i=0;i<n;i++)
    {
        printval(coef[i],m);
        printf("%s%d\n",rest[cont[i]],goal[i]);
    }
    return 0;
}
