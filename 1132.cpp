#include<bits/stdc++.h>

using namespace std;

#define MAX 55


typedef long long ll;
int sz;

unsigned int nCr[55][55];

void cal()
{
    int i,j;
    for(i=0; i<MAX; ++i)
    {
        nCr[i][i]=nCr[i][0]=1;
        nCr[i][1]=i;
    }
    for(i=1; i<MAX; ++i)
    {
        for(j=2; j<i; ++j)
            nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
    }
}

struct mat22{
    unsigned int r, c;
    unsigned int mat[MAX][MAX];
    void init(unsigned int i,unsigned int j)
    {
        r=i;
        c=j;
    }
} a,b;

typedef struct mat22 mat22;


mat22 mul(mat22 a, mat22 b)
{
    mat22 ret;
    ret.init(a.r,b.c);
    int i,j,k,l;
    for(i=0; i<a.r; ++i)
    {
        for(j=0; j<b.c; ++j)
        {
            ret.mat[i][j]=0;
            for(k=0; k<a.c; ++k)
            {
                ret.mat[i][j]=(ret.mat[i][j]+(a.mat[i][k]*b.mat[k][j]) );
            }
        }
    }
    return ret;
}

mat22 power(mat22 a, ll n)
{
    if(n==1)
        return a;
    mat22 ret=power(a,n/2);
    ret = mul(ret, ret);
    if(n%2)
        ret = mul(ret,a);
    ret.init(sz,sz);
    return ret;

}

int main()
{
    int t,ti;
    unsigned int ans;
    ll n,k;
    mat22 temp;
    int i,j;
    cal();
    for(i=0; i<MAX; ++i)
        a.mat[0][i]=1;
    for(i=1; i<MAX; ++i)
    {
        a.mat[i][1]=1;
        for(j=2; j<=i; ++j)
        {
            a.mat[i][j]=nCr[i-1][j-1];
        }
    }
    b.mat[0][0]=b.mat[1][0]=1;
    for(i=2; i<MAX; ++i)
        b.mat[i][0]=1;
    //printf("%u\n",b.mat[31][0]);
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld",&n,&k);
        a.init(k+2,k+2);
        b.init(k+2,1);
        if(n==1)
            ans=1;
        else
        {
            temp=power(a,n-1);
            temp=mul(temp,b);
            ans=temp.mat[0][0];
        }
        printf("Case %d: %u\n",ti,ans);
    }

    return 0;
}
