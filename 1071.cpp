#include<bits/stdc++.h>
using namespace std;

#define inf 999999999

int n,m;
int dp[110][110][210],a[110][110];

int cal(int r1,int r2,int total)
{
    int c1,c2;
    c1=total-r1;
    c2=total-r2;
    if(r1==n-1 && r2==n-1 && c1==m-1 && c2==m-1)
        return a[r1][c1];
    if(r1==n || r2==n || c1==m || c2==m)
        return -inf;
    if(r1==r2 && c1==c2)
        return -inf;
    if(dp[r1][r2][total] != -1)
        return dp[r1][r2][total];
    int ret=cal(r1+1,r2+1,total+1);
    ret = max(ret, cal(r1+1,r2,total+1));
    ret = max(ret, cal(r1,r2+1,total+1));
    ret = max(ret, cal(r1,r2,total+1));
    return dp[r1][r2][total]=ret+a[r1][c1]+a[r2][c2];

}

int main()
{
    int t,ti,i,j,k;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d",&n,&m);
        memset(dp,-1,sizeof(dp));
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
                scanf("%d",&a[i][j]);
        }
        printf("Case %d: %d\n",ti,a[0][0]+cal(0,1,1));
    }
    return 0;
}
