#include<bits/stdc++.h>
#define MAX 1010

#define eps 1e-9

double dp[MAX][MAX];

long long nC2(long long n)
{
    return (n*(n-1))/2;
}

double cal(int t,int d)
{
    if(t<0 || d<0)
        return 0;
    if(t==0)
        return 1;
    if(dp[t][d] == dp[t][d])
        return dp[t][d];
    double down= nC2(t+d+1);
    double ret;
    ret=(nC2(t)/down)*cal(t-2,d);
    ret+=((t*d)/down)*cal(t,d-1);
    return dp[t][d]=ret/(1-((d+nC2(d))/down));
}

int main()
{
    int T,ti,t,d;
    scanf("%d",&T);
    for(ti=1; ti<=T; ++ti)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&t,&d);
        printf("Case %d: %.8lf\n",ti,cal(t,d));
    }
    return 0;
}
