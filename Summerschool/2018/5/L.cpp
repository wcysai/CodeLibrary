
/*Code to count number of non-equivilent expression with n variables
 */
#include <stdio.h>
#include <gmp.h>
#define N 201
mpz_t SC[N];///Count of number start from multiplication or sum
mpz_t SA[N];
mpz_t SC1[N];
mpz_t SA1[N];
mpz_t fact[N];
mpz_t p2m1[N];
int ind[N];


void get_comb(int n, int g, mpz_t comb)
{
    int i,c;
    mpz_t tmp;
    mpz_init(tmp);
    mpz_set(comb,fact[n]);
    c=0;
    do{
        int t,k,j;
        for(i=c+1;i<g;i++){
            if(ind[i]!=ind[c])
                break;
        }///c to i-1 is same
        t=ind[c];
        k=i-c;
#ifdef TRACE
        fprintf(stderr,"k=%d,t=%d,fact[%d]=",k,t,t*k);
        mpz_out_str(stderr,10,fact[t*k]);
        fprintf(stderr,"\n");
#endif
        for(j=0;j<k;j++)mpz_div(comb,comb,fact[t]);
        mpz_div(comb,comb,fact[k]);
        c=i;
    }while(c<g);
#ifdef TRACE
    fprintf(stderr,"comb(%d,%d)=",n,g);
    mpz_out_str(stderr,10,comb);
    fprintf(stderr,"\n");
#endif
    mpz_clear(tmp);
}

void accum(int n, int g)
{
    mpz_t tmp,tmp2,tmp3,tmp4;
    int i;
    mpz_init(tmp);
    mpz_init(tmp2);
    mpz_init(tmp3);
#ifdef TRACE
    mpz_init(tmp4);
    fprintf(stderr,"%d=%d",n,ind[0]);
    for(i=1;i<g;i++){
        fprintf(stderr,"+%d",ind[i]);
    }
    fprintf(stderr,"\n");
#endif
    mpz_set_ui(tmp,1);
    for(i=0;i<g;i++){
        mpz_mul(tmp,tmp,SA[ind[i]]);
    }
    get_comb(n,g,tmp2);
    mpz_mul(tmp,tmp,tmp2);
    mpz_mul(tmp,tmp,p2m1[g]);
#ifdef TRACE
    fprintf(stderr,"Prod: ");
    mpz_out_str(stderr,10,tmp);
    mpz_set(tmp4,tmp);
#endif
    mpz_add(SC[n],SC[n],tmp);
    mpz_set_ui(tmp,1);
    for(i=0;i<g;i++){
        mpz_mul(tmp,tmp,SA1[ind[i]]);
    }
    mpz_mul(tmp,tmp,tmp2);
    mpz_mul(tmp,tmp,p2m1[g]);
#ifdef TRACE
    fprintf(stderr,"\nProd Add only: ");
    mpz_out_str(stderr,10,tmp);
    mpz_add(tmp4,tmp4,tmp4);
    mpz_sub(tmp4,tmp4,tmp);
    fprintf(stderr,"\nPROD:");
    mpz_out_str(stderr,10,tmp4);
#endif
    mpz_add(SC1[n],SC1[n],tmp);
    
    mpz_set_ui(tmp,1);
    for(i=0;i<g;i++){
        mpz_mul(tmp,tmp,SC[ind[i]]);
    }
    mpz_mul(tmp,tmp,tmp2);
    mpz_add_ui(tmp3, p2m1[g-1],1);
    mpz_mul(tmp,tmp,tmp3);
#ifdef TRACE
    fprintf(stderr,"\nSum: ");
    mpz_out_str(stderr,10,tmp);
    mpz_set(tmp4,tmp);
#endif
    mpz_add(SA[n],SA[n],tmp);
    mpz_set_ui(tmp,1);
    for(i=0;i<g;i++){
        mpz_mul(tmp,tmp,SC1[ind[i]]);
    }
    mpz_mul(tmp,tmp,tmp2);
#ifdef TRACE
    fprintf(stderr,"\nSum add only: ");
    mpz_out_str(stderr,10,tmp);
    mpz_add(tmp4,tmp4,tmp4);
    mpz_sub(tmp4,tmp4,tmp);
    fprintf(stderr,"\nSUM: ");
    mpz_out_str(stderr,10,tmp4);
    fprintf(stderr,"\n");
    mpz_clear(tmp4);
#endif
    mpz_add(SA1[n],SA1[n],tmp);
    mpz_clear(tmp3);
    mpz_clear(tmp2);
    mpz_clear(tmp);
}

void try_index(int n, int g, int cur_g, int left)
{
    int max=left-cur_g;
    int min=(left+cur_g)/(cur_g+1);
    int i;
    if(cur_g==0){
        ind[cur_g]=left;
        accum(n,g);
        return;
    }
    if(cur_g<g-1&&max>ind[cur_g+1]){
        max=ind[cur_g+1];
    }
    for(i=min;i<=max;i++){
        ind[cur_g]=i;
        try_index(n, g, cur_g-1, left-i);
    }
}

void count_group(int n, int g)
{
    try_index(n, g, g-1,n);
}

void count(int n)
{
    int g;
    mpz_t sum;
    mpz_init(sum);
    mpz_set_ui(SC[n],0);
    mpz_set_ui(SA[n],0);
    mpz_set_ui(SC1[n],0);
    mpz_set_ui(SA1[n],0);
    for(g=2;g<=n;g++){
        count_group(n,g);
    }
    printf("C[%d]=",n);
    mpz_add(sum,SC[n],SC[n]);
    mpz_add(sum,sum, SA[n]);
    mpz_add(sum,sum, SA[n]);
    mpz_sub(sum, sum, SC1[n]);
    mpz_sub(sum, sum, SA1[n]);
    mpz_out_str(stdout,10,sum);
    printf("\n");
#ifdef TRACE
    fprintf(stderr,"SC[%d]=",n);
    mpz_out_str(stderr,10,SC[n]);
    fprintf(stderr,"\nSC1[%d]=",n);
    mpz_out_str(stderr,10,SC1[n]);
    fprintf(stderr,"\nSA[%d]=",n);
    mpz_out_str(stderr,10,SA[n]);
    fprintf(stderr,"\nSA1[%d]=",n);
    mpz_out_str(stderr,10,SA1[n]);
    fprintf(stderr,"\n");
#endif
    fflush(stdout);
    mpz_clear(sum);
}


void init()
{
    int i;
    for(i=0;i<N;i++){
        mpz_init(SC[i]);
        mpz_init(SA[i]);
        mpz_init(SC1[i]);
        mpz_init(SA1[i]);
    }
    for(i=0;i<N;i++)mpz_init(fact[i]);
    for(i=0;i<N;i++)mpz_init(p2m1[i]);
    mpz_set_ui(SC[1],1);
    mpz_set_ui(SA[1],1);
    mpz_set_ui(SC1[1],1);
    mpz_set_ui(SA1[1],1);
    mpz_set_ui(fact[1],1);
    mpz_set_ui(p2m1[1],1);
    for(i=2;i<N;i++){
        mpz_mul_ui(fact[i],fact[i-1],i);
        mpz_mul_ui(p2m1[i],p2m1[i-1],2);
        mpz_add_ui(p2m1[i],p2m1[i],1);
    }
}

int main()
{
    int i;
    init();
    for(i=2;i<N;i++)
        count(i);
}
