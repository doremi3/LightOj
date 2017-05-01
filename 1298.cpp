#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 505
#define MOD 1000000007

ll prime[MAX],dp[MAX][MAX],k,p,power[510];

bool state[5000];

void seive()
{
    int i,j;
    for(i=2; i<100; ++i)
    {
        for(j=i*i; j<4000; j+=i)
            state[j]=1;
    }
    j=0;
    for(i=2; i<4000; ++i)
    {
        if(!state[i])
            prime[j++]=i;
        if(j==500)
            break;
    }

}

ll cal(int i,int ki)
{
    if(ki<=0)
        return 0;
    if(i==0)
        return power[ki];
    if(dp[i][ki] != -1)
        return dp[i][ki];
    int j,curr,ret=0;
    curr=prime[i];
    for(j=1; j<ki; ++j)
    {
        ret=(ret+ (curr*cal(i-1, ki-j))%MOD)%MOD;
        curr=(curr*prime[i])%MOD;
    }
    return dp[i][ki]=ret;
}

ll expo(ll a,ll n)
{
    if(n==0)
        return 1;
    ll ret=expo(a,n/2);
    ret=(ret*ret)%MOD;
    if(n%2)
        ret=(ret*a)%MOD;
    return ret;
}
int main()
{
    int t,ti,i;
    ll curr,ans;
    seive();
    power[0]=1;
    for(t=1; t<=500; ++t)
        power[t]=(power[t-1]*2)%MOD;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld",&k,&p);
        ans=cal(p-1,k);
        curr=1;
        for(i=0; i<p; ++i)
        {
            ans=(ans*(prime[i]-1))%MOD;
            curr=(curr*prime[i])%MOD;
        }
        curr=expo(curr,MOD-2);
        ans=(ans*curr)%MOD;
        printf("Case %d: %lld\n",ti,ans);
    }
    return 0;
}
