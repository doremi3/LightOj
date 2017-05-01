#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 503

int ura[MAX][MAX],sura[MAX][MAX],rad[MAX][MAX],srad[MAX][MAX],dp[MAX][MAX];
int m,n;

int cal(int i,int j)
{
    if(i<1 || j<1)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ret1,ret2;
    ret1=sura[i][j]+cal(i-1,j);
    ret2=srad[i][j]+cal(i,j-1);
    return dp[i][j]=max(ret1,ret2);
}

int main()
{
    int t,ti,i,j,k;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d",&m, &n);
        for(i=1; i<=m; ++i)
        {
            for(j=1; j<=n; ++j){
                scanf("%d",&ura[i][j]);
                sura[i][j]=sura[i][j-1]+ura[i][j];
            }
        }
        for(i=1; i<=m; ++i)
        {
            for(j=1; j<=n; ++j){
                scanf("%d",&rad[i][j]);
                srad[i][j]=srad[i-1][j]+rad[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",ti,cal(m,n));
    }
    return 0;
}
