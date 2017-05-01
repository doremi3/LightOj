#include<bits/stdc++.h>
using namespace std;

#define MAX 18
#define MAXSZ 100010
#define inf 999999999

int same[MAX][MAX], dp[MAXSZ],x[MAX],y[MAX],n,a[MAXSZ],an;

int setbit(int a,int p)
{
    return a|(1<<p);
}

bool checkbit(int a, int p)
{
    return a&(1<<p);
}

int uni(int a,int b)
{
    return a|b;
}

int cal(int mask)
{
    if(mask==((1<<n)-1) )
        return 0;
    if(dp[mask] != -1)
        return dp[mask];
    int i,j,temp,cnt,mini=inf;
    temp=mask;
    i=cnt=0;
    for(i=0; i<n; ++i)
    {
        if(checkbit(mask,i)==0)
            break;
    }
    for(j=i+1; j<n; ++j)
    {
        if(checkbit(mask,j)==0)
        {
            mini=min(mini,1+cal(mask|same[i][j]));
            cnt=1;
        }
    }
    if(cnt==0)
        return 1;
    //printf("%d %d\n",mask,mini);
    return dp[mask]=mini;
}
int main()
{
    int t,ti,i,k,m,j,mask,temp,ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        memset(same,0,sizeof(same));
        memset(dp,-1,sizeof(dp));
        for(i=0; i<n; ++i)
            scanf("%d %d",&x[i],&y[i]);
        an=0;
        for(i=0; i<n; ++i)
        {
            mask=0;
            mask=setbit(mask,i);
            for(j=0; j<n; ++j)
            {
                if(j==i)
                    continue;
                temp=setbit(mask,j);
                for(k=0; k<n; ++k)
                {
                    if(j==k || i==k)
                        continue;
                    if((y[j]-y[i])*(x[k]-x[i])==(x[j]-x[i])*(y[k]-y[i]))
                        temp=setbit(temp,k);
                }
                same[i][j]=temp;
            }
        }
        if(n==1)
            ans=1;
        else
            ans=cal(0);
        printf("Case %d: %d\n",ti,ans);
    }
    return 0;
}
