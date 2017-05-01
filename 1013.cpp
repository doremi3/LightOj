#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 34

int dp[MAX][MAX];
long long c[MAX][MAX][MAX];

char a[MAX],b[MAX];

long long na,nb,l;

long long cnt(long long i,long long j, long long len)
{
    if(len==l && i==na && j==nb)
        return 1;
    if(len==l)
        return 0;
    if(i==na || j==nb)
        return ((na-i+nb-j)==l-len);
    if(c[i][j][len] != -1)
        return c[i][j][len];
    if(a[i]==b[j])
        return c[i][j][len]= cnt(i+1,j+1,len+1);
    return c[i][j][len] = cnt(i,j+1,len+1)+cnt(i+1,j,len+1);
}

int findmax(int i,int j)
{
    if(i==na || j==nb)
        return nb-j+na-i;

    if(dp[i][j] != -1)
        return dp[i][j];
    if(a[i]==b[j])
        return dp[i][j]=1+findmax(i+1,j+1);
    return dp[i][j]=1+min(findmax(i+1,j),findmax(i,j+1));
}

int main()
{
    int t,i,ti;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%s %s",a,b);
        memset(dp,-1,sizeof(dp));
        memset(c,-1,sizeof(c));
        na=strlen(a);
        nb=strlen(b);
        l=findmax(0,0);
        printf("Case %d: %lld %lld\n",ti,l,cnt(0,0,0));
    }
    return 0;
}
