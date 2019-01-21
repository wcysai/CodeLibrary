/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 20:49:53
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define INF 1000000000
#define MOD 1000000007
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;

class BigNum
{
public:
    int a[500];    //¿ÉÒÔ¿ØÖÆŽóÊýµÄÎ»Êý
    int len;       //ŽóÊý³€¶È
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //¹¹Ôìº¯Êý
    BigNum(const int);       //œ«Ò»žöintÀàÐÍµÄ±äÁ¿×ª»¯ÎªŽóÊý
    BigNum(const char*);     //œ«Ò»žö×Ö·ûŽ®ÀàÐÍµÄ±äÁ¿×ª»¯ÎªŽóÊý
    BigNum(const BigNum &);  //¿œ±Ž¹¹Ôìº¯Êý
    BigNum &operator=(const BigNum &);   //ÖØÔØž³ÖµÔËËã·û£¬ŽóÊýÖ®ŒäœøÐÐž³ÖµÔËËã

    friend istream& operator>>(istream&,  BigNum&);   //ÖØÔØÊäÈëÔËËã·û
    friend ostream& operator<<(ostream&,  BigNum&);   //ÖØÔØÊä³öÔËËã·û

    BigNum operator+(const BigNum &) const;   //ÖØÔØŒÓ·šÔËËã·û£¬ÁœžöŽóÊýÖ®ŒäµÄÏàŒÓÔËËã
    BigNum operator-(const BigNum &) const;   //ÖØÔØŒõ·šÔËËã·û£¬ÁœžöŽóÊýÖ®ŒäµÄÏàŒõÔËËã
    BigNum operator*(const BigNum &) const;   //ÖØÔØ³Ë·šÔËËã·û£¬ÁœžöŽóÊýÖ®ŒäµÄÏà³ËÔËËã
    BigNum operator/(const int   &) const;    //ÖØÔØ³ý·šÔËËã·û£¬ŽóÊý¶ÔÒ»žöÕûÊýœøÐÐÏà³ýÔËËã

    BigNum operator^(const int  &) const;    //ŽóÊýµÄnŽÎ·œÔËËã
    int    operator%(const int  &) const;    //ŽóÊý¶ÔÒ»žöintÀàÐÍµÄ±äÁ¿œøÐÐÈ¡Ä£ÔËËã
    bool   operator>(const BigNum & T)const;   //ŽóÊýºÍÁíÒ»žöŽóÊýµÄŽóÐ¡±ÈœÏ
    bool   operator>(const int & t)const;      //ŽóÊýºÍÒ»žöintÀàÐÍµÄ±äÁ¿µÄŽóÐ¡±ÈœÏ

    void print();       //Êä³öŽóÊý
};
BigNum::BigNum(const int b)     //œ«Ò»žöintÀàÐÍµÄ±äÁ¿×ª»¯ÎªŽóÊý
{
    int c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const char*s)     //œ«Ò»žö×Ö·ûŽ®ÀàÐÍµÄ±äÁ¿×ª»¯ÎªŽóÊý
{
    int t,k,index,l,i;
    memset(a,0,sizeof(a));
    l=strlen(s);
    len=l/DLEN;
    if(l%DLEN)
        len++;
    index=0;
    for(i=l-1;i>=0;i-=DLEN)
    {
        t=0;
        k=i-DLEN+1;
        if(k<0)
            k=0;
        for(int j=k;j<=i;j++)
            t=t*10+s[j]-'0';
        a[index++]=t;
    }
}
BigNum::BigNum(const BigNum & T) : len(T.len)  //¿œ±Ž¹¹Ôìº¯Êý
{
    int i;
    memset(a,0,sizeof(a));
    for(i = 0 ; i < len ; i++)
        a[i] = T.a[i];
}
BigNum & BigNum::operator=(const BigNum & n)   //ÖØÔØž³ÖµÔËËã·û£¬ŽóÊýÖ®ŒäœøÐÐž³ÖµÔËËã
{
    int i;
    len = n.len;
    memset(a,0,sizeof(a));
    for(i = 0 ; i < len ; i++)
        a[i] = n.a[i];
    return *this;
}
istream& operator>>(istream & in,  BigNum & b)   //ÖØÔØÊäÈëÔËËã·û
{
    char ch[MAXSIZE*4];
    int i = -1;
    in>>ch;
    int l=strlen(ch);
    int count=0,sum=0;
    for(i=l-1;i>=0;)
    {
        sum = 0;
        int t=1;
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)
        {
            sum+=(ch[i]-'0')*t;
        }
        b.a[count]=sum;
        count++;
    }
    b.len =count++;
    return in;

}
ostream& operator<<(ostream& out,  BigNum& b)   //ÖØÔØÊä³öÔËËã·û
{
    int i;
    cout << b.a[b.len - 1];
    for(i = b.len - 2 ; i >= 0 ; i--)
    {
        cout.width(DLEN);
        cout.fill('0');
        cout << b.a[i];
    }
    return out;
}

BigNum BigNum::operator+(const BigNum & T) const   //ÁœžöŽóÊýÖ®ŒäµÄÏàŒÓÔËËã
{
    BigNum t(*this);
    int i,big;      //Î»Êý
    big = T.len > len ? T.len : len;
    for(i = 0 ; i < big ; i++)
    {
        t.a[i] +=T.a[i];
        if(t.a[i] > MAXN)
        {
            t.a[i + 1]++;
            t.a[i] -=MAXN+1;
        }
    }
    if(t.a[big] != 0)
        t.len = big + 1;
    else
        t.len = big;
    return t;
}
BigNum BigNum::operator-(const BigNum & T) const   //ÁœžöŽóÊýÖ®ŒäµÄÏàŒõÔËËã
{
    int i,j,big;
    bool flag;
    BigNum t1,t2;
    if(*this>T)
    {
        t1=*this;
        t2=T;
        flag=0;
    }
    else
    {
        t1=T;
        t2=*this;
        flag=1;
    }
    big=t1.len;
    for(i = 0 ; i < big ; i++)
    {
        if(t1.a[i] < t2.a[i])
        {
            j = i + 1;
            while(t1.a[j] == 0)
                j++;
            t1.a[j--]--;
            while(j > i)
                t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i];
        }
        else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while(t1.a[t1.len - 1] == 0 && t1.len > 1)
    {
        t1.len--;
        big--;
    }
    if(flag)
        t1.a[big-1]=0-t1.a[big-1];
    return t1;
}

BigNum BigNum::operator*(const BigNum & T) const   //ÁœžöŽóÊýÖ®ŒäµÄÏà³ËÔËËã
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i = 0 ; i < len ; i++)
    {
        up = 0;
        for(j = 0 ; j < T.len ; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if(temp > MAXN)
            {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if(up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
BigNum BigNum::operator/(const int & b) const   //ŽóÊý¶ÔÒ»žöÕûÊýœøÐÐÏà³ýÔËËã
{
    BigNum ret;
    int i,down = 0;
    for(i = len - 1 ; i >= 0 ; i--)
    {
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
    }
    ret.len = len;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
int BigNum::operator %(const int & b) const    //ŽóÊý¶ÔÒ»žöintÀàÐÍµÄ±äÁ¿œøÐÐÈ¡Ä£ÔËËã
{
    int i,d=0;
    for (i = len-1; i>=0; i--)
    {
        d = ((d * (MAXN+1))% b + a[i])% b;
    }
    return d;
}
BigNum BigNum::operator^(const int & n) const    //ŽóÊýµÄnŽÎ·œÔËËã
{
    BigNum t,ret(1);
    int i;
    if(n<0)
        exit(-1);
    if(n==0)
        return 1;
    if(n==1)
        return *this;
    int m=n;
    while(m>1)
    {
        t=*this;
        for( i=1;i<<1<=m;i<<=1)
        {
            t=t*t;
        }
        m-=i;
        ret=ret*t;
        if(m==1)
            ret=ret*(*this);
    }
    return ret;
}
bool BigNum::operator>(const BigNum & T) const   //ŽóÊýºÍÁíÒ»žöŽóÊýµÄŽóÐ¡±ÈœÏ
{
    int ln;
    if(len > T.len)
        return true;
    else if(len == T.len)
    {
        ln = len - 1;
        while(a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if(ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
bool BigNum::operator >(const int & t) const    //ŽóÊýºÍÒ»žöintÀàÐÍµÄ±äÁ¿µÄŽóÐ¡±ÈœÏ
{
    BigNum b(t);
    return *this>b;
}

void BigNum::print()    //Êä³öŽóÊý
{
    int i;
    cout << a[len - 1];
    for(i = len - 2 ; i >= 0 ; i--)
    {
        cout.width(DLEN);
        cout.fill('0');
        cout << a[i];
    }
}
BigNum k(1);
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) k=k*2;
    k.print();k=k/2;printf(" ");k.print();
    puts("");
    return 0;
}

