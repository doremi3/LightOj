#include<stdio.h>
#include<string.h>

typedef long long ll;

#define MOD 1000000007

ll dp[2002][1002][2002];

ll a[2002],b[1002];
ll n,m;

ll cal(int i,int j, int last)
{
          // printf("%d %d\n",i,j);
    if(j==m)
        return 1;
    if(i==n)
        return 0;
    if(last >=0 && dp[i][j][last] !=-1)
        return dp[i][j][last];
    ll ret;
    if((j==0) || (j > 0 && (a[i]+b[j] >= a[last]+b[j-1])))
        ret = (cal(i+1, j+1, i) + cal(i+1, j, last))%MOD;
    else
        ret = cal(i+1, j, last);
    return dp[i][j][last]=ret;
}

int main()
{
    int i,j;
    ll ans;
    scanf("%lld %lld",&n,&m);
    memset(dp,-1,sizeof(dp));
    for(i=0; i<n; ++i)
        scanf("%lld",&a[i]);
    for(i=0; i<m; ++i)
        scanf("%lld",&b[i]);
    ans=cal(0,0,-1);
    printf("%lld\n",ans);

    return 0;
}
