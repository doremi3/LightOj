#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
#define MOD 1000000007

typedef long long ll;

ll f[MAX+10],a[1010],n;

ll power(ll a,ll p)
{
    if(p==0)
        return 1;
    ll ret=power(a,p/2);
    ret=(ret*ret)%MOD;
    if(p%2)
        ret=(ret*a)%MOD;
    return ret;
}

void factorial()
{
    int i;
    f[0]=1;
    for(i=1; i<=MAX; ++i)
        f[i]=(i*f[i-1])%MOD;

}

ll cal()
{
    ll i,j,k,curr,sum,ret=1;
    sum=0;
    for(i=0; i<n; ++i)
    {
        curr=(f[sum+a[i]-1]*power(f[sum],MOD-2))%MOD;
        curr*=power(f[a[i]-1],MOD-2);
        curr%=MOD;
        ret=(ret*curr)%MOD;
        sum+=a[i];
    }
    return ret;
}

int main()
{
    ll t,ti,i,k,j;
    factorial();
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld",&n);
        for(i=0; i<n; ++i)
            scanf("%lld",&a[i]);
        printf("Case %lld: %lld\n",ti,cal());
    }
    return 0;
}
