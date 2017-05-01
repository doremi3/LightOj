#include<bits/stdc++.h>
using namespace std;

#define inf 99999999

int p[105],w[105],c[105],dp[105][10005],W,n;

int cal(int i, int sum)
{
    if(sum>W)
        return -inf;
    if(sum==W || i==n)
        return 0;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    return dp[i][sum]=max(cal(i+1,sum),p[i]+cal(i,sum+w[i]));
}

int main()
{
    int t,ti,i,j,k,sum;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d",&n,&W);
        sum=0;
        for(i=0; i<n; ++i)
        {
            scanf("%d %d %d",&p[i],&c[i],&w[i]);
            sum+=w[i]*c[i];
        }
        W=W-sum;
        memset(dp,-1,sizeof(dp));
        if(W<0)
            printf("Case %d: Impossible\n",ti);
        else
            printf("Case %d: %d\n",ti,cal(0,0));
    }
    return 0;
}
