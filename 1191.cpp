#include<bits/stdc++.h>
using namespace std;

long long dp[53],sum[53],n,m,k;

long long cal()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=0; i<=n; ++i)
        sum[i]=1;
    for(i=1; i<=k; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            dp[j]=sum[j-1];
            if(j-m-1>=0)
                dp[j]-=sum[j-m-1];
          //  printf("%d %d %lld\n",i,j,dp[j]);
        }
        sum[0]=0;
        for(j=1; j<=n; ++j)
            sum[j]=sum[j-1]+dp[j];
    }
    return dp[n];
}

int main()
{
    int t,ti;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld %lld",&n,&k,&m);
        printf("Case %d: %lld\n",ti,cal());
    }
    return 0;
}
