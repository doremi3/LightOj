#include<bits/stdc++.h>
using namespace std;

#define MAX 1008

int dp[MAX][2],b0[MAX],b1[MAX],ltor[MAX],rtol[MAX],n;

int cal(int i,int b)
{
    if(i==n-1)
    {
         if(b==0)
            return b0[i];
         return b1[i];
    }
    if(dp[i][b] != -1)
        return dp[i][b];
    int ret;
    if(b==0)
        ret=min(cal(i+1,b), cal(i+1,1)+ltor[i])+b0[i];
    else
        ret=min(cal(i+1,b), cal(i+1,0)+rtol[i])+b1[i];
    return dp[i][b]=ret;
}

int main()
{
    int t,ti,i,j;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        for(i=0; i<n; ++i)
            scanf("%d",&b0[i]);
        for(i=0; i<n; ++i)
            scanf("%d",&b1[i]);
        for(i=0; i<n-1; ++i)
            scanf("%d",&ltor[i]);
        for(i=0; i<n-1; ++i)
            scanf("%d",&rtol[i]);
        ltor[n-1]=rtol[n-1]=0;
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",ti,min(cal(0,0),cal(0,1)) );
    }
    return 0;
}
