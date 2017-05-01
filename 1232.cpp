#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 100000007

ll dp[10010],a[110],n,k;



int main()
{
    ll t,ti;
    ll i,j;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld",&n, &k);
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; ++i)
            scanf("%lld",&a[i]);
        dp[0]=1;
        for(i=0; i<n; ++i)
        {
            for(j=a[i]; j<=k; ++j)
                dp[j]=(dp[j] + dp[j-a[i]])%MOD;
        }
        printf("Case %lld: %lld\n",ti,dp[k]);
    }
    return 0;
}
