#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 100000007

ll dp[15005],n,k,s,sum[15005];

ll cal()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i=0; i<=s; ++i)
        sum[i]=1;
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=s; ++j)
        {
            dp[j]=sum[j-1];
            if(j-k>0)
                dp[j]=(dp[j]+MOD-sum[j-k-1])%MOD;
           // printf("%lld\n",dp[i][j],j,k);
        }
        sum[0]=0;
        for(j=1; j<=s; ++j)
            sum[j]=(sum[j-1]+dp[j])%MOD;
    }
    return dp[s];
}

int main()
{
    int t,ti;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld %lld",&n,&k,&s);
        printf("Case %d: %lld\n",ti,cal());
    }
    return 0;
}
