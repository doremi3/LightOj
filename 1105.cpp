#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef long long ll;

ll dp[50],sum[50],flag[50];

void cal()
{
    int i,j,k,l;
    dp[1]=dp[2]=sum[1]=1;
    sum[2]=2;

    for(i=3; i<45;  ++i)
    {
        dp[i]=1+sum[i-2];
        sum[i]=dp[i]+sum[i-1];
        //printf("%d\n",dp[i]);
    }

}

int main()
{
    int t,ti,i,n,j,m,save;
    cal();
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        printf("Case %d: ",ti);
        memset(flag,0,sizeof(flag));
        m=n;
        save=1;
        while(m>1)
        {
           // printf("%d m\n",m);
            for(i=1; i<45; ++i)
            {
                if(sum[i]>=m)
                {
                    //printf("%d m\n",i);
                    flag[i]=1;
                    save=max(save,i);
                    m=m-sum[i-1]-1;
                    break;
                }
            }
        }
        if(m==1)
            flag[1]=1;
        for(i=save; i>=1; --i)
            printf("%d",flag[i]);
        puts("");
    }
    return 0;
}
