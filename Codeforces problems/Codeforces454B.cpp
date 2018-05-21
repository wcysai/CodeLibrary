#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    bool f=false;
    if(n>m) {swap(n,m); f=true;}
    mat A(n,vec(m));
    if(m<=2||(n==2&&m==3)||(n==1&&m==3))
    {
        printf("NO\n");
        return 0;
    }
    if(m==3&&n==3)
    {
        printf("5 3 4\n7 1 9\n2 6 8");
        return 0;
    }
    printf("YES\n");
    int disp=0;
    for(int i=0;i<n;i++)
    {
        int sty=0,stx=i,k=i*m+1+disp;
        for(int j=0;j<m;j++)
        {
            if(sty>=m) sty-=m;
            if(stx>=n) stx-=n;
            if(k>(i+1)*m) k=i*m+1;
            A[stx][sty]=k;
            stx++;
            sty++;
            k++;
        }
        disp=(disp+(m/2))%m;
    }
    if(!f)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d ",A[i][j]);
            printf("\n");
        }
    }
    else
    {
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",A[j][i]);
            printf("\n");
        }
    }
    return 0;
}


