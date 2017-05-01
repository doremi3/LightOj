#include<bits/stdc++.h>
using namespace std;

#define MOD 1000007

long long a[100010],sum[100010];

int main()
{
    long long t,ti,i,j,k,n,c,ans;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld %lld %lld",&k,&c,&n,&a[0]);
        for(i=1; i<n; ++i)
            a[i]=(((a[i-1]*k)%MOD)+c)%MOD;
        sort(a,a+n);

        sum[0]=a[0];
        for(i=1; i<n; ++i)
            sum[i]=(sum[i-1]+a[i]);
        ans=0;
        for(i=0; i<n; ++i)
            ans+=sum[n-1]-sum[i]-(n-i-1)*a[i];
        printf("Case %lld: %lld\n",ti,ans);
    }
    return 0;
}
