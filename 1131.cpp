#include<bits/stdc++.h>
using namespace std;

#define sz 6

typedef long long ll;

struct mat22{
    ll r, c;
    long long mat[7][7];
    void init(ll i,ll j)
    {
        r=i;
        c=j;
    }
} a,b;

typedef struct mat22 mat22;

long long m;

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
                ret.mat[i][j]=(ret.mat[i][j]+(a.mat[i][k]*b.mat[k][j])%m )%m;
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
    ret.init(6,6);
    return ret;

}

int main()
{
    long long t,ti,q,n,i,j,k;
    mat22 temp;
    a.init(6,6);
    b.init(6,1);
    a.mat[1][0]=a.mat[2][1]=a.mat[4][3]=a.mat[5][4]=1;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld %lld",&a.mat[0][0], &a.mat[0][1], &a.mat[0][5]);
        scanf("%lld %lld %lld",&a.mat[3][3], &a.mat[3][4], &a.mat[3][2]);
        scanf("%lld %lld %lld", &b.mat[2][0], &b.mat[1][0], &b.mat[0][0]);
        scanf("%lld %lld %lld", &b.mat[5][0], &b.mat[4][0], &b.mat[3][0]);
        scanf("%lld",&m);
        scanf("%lld",&q);
        printf("Case %lld:\n",ti);
        while(q--)
        {
            scanf("%lld",&n);
            if(n>=3)
            {
                temp=power(a,n-2);
                temp=mul(temp,b);
            }
            if(n==0)
                printf("%lld %lld\n",b.mat[2][0]%m, b.mat[5][0]%m);
            else if(n==1)
                printf("%lld %lld\n",b.mat[1][0]%m, b.mat[4][0]%m);
            else if(n==2)
                printf("%lld %lld\n",b.mat[0][0]%m, b.mat[3][0]%m);
            else
                printf("%lld %lld\n",temp.mat[0][0], temp.mat[3][0]);

        }
    }
    return 0;
}
