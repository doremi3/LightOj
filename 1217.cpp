#include<bits/stdc++.h>
using namespace std;

#define inf 99999999

int n,a[1007],dp[1010][2];
bool f;

int cal(int i, bool s)
{
    if(i==n)
    {
        if(s==0 || f==1)
            return 0;
        return a[n];
    }
    if(dp[i][s] != -1)
        return dp[i][s];
    if(s==0)
        return dp[i][s]=cal(i+1,1);
    return dp[i][s]=max(cal(i+1,1), a[i]+cal(i+1,0));
}

int main()
{
    int t,ti,i,j,k,ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        for(i=1; i<=n; ++i)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        f=0;
        ans=cal(2,1);
        memset(dp,-1,sizeof(dp));
        f=1;
        ans=max(ans,cal(2,0)+a[1]);
        printf("Case %d: %d\n",ti,ans);
    }
    return 0;
}
