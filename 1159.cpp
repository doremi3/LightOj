#include<bits/stdc++.h>

using namespace std;

#define MAX 52

char a[MAX],b[MAX],c[MAX];
int la,lb,lc;
int dp[MAX][MAX][MAX];

int cal(int i,int j,int k)
{
   // printf("%d %d %d\n",i,j,k);
    if(i==la || j==lb || k==lc)
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    if(a[i]==b[j] && b[j]==c[k])
        return dp[i][j][k]=1+cal(i+1,j+1,k+1);
    return dp[i][j][k]=max(cal(i+1,j,k),max(cal(i,j+1,k),cal(i,j,k+1)));
}

int main()
{
    int t,ti;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%s %s %s",a,b,c);
        la=strlen(a);
        lb=strlen(b);
        lc=strlen(c);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",ti,cal(0,0,0));
    }
    return 0;
}
