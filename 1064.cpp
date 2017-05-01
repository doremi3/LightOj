#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[30][200],p[30];

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll cal(int ni,int xi)
{
    if(ni==0 && xi==0)
        return 1;
    if(xi<=0|| ni<=0)
        return 0;
    if(dp[ni][xi] != -1)
        return dp[ni][xi];
    ll ret=0;
    int i;
    for(i=1; i<=6; ++i)
        ret+=cal(ni-1,xi-i);
    return dp[ni][xi]=ret;

}

int main()
{
    int t,ti,n,i,x;
    ll q,P,g;
    p[0]=1;
    for(i=1; i<=25; ++i)
        p[i]=(long long)(6)*p[i-1];
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d",&n,&x);
        q=0;
        for( ; x<=n*6; ++x)
            q+=cal(n,x);
        P=p[n];
        g=gcd(P,q);
        P/=g;
        q/=g;
        if(P==1 || q==0)
            printf("Case %d: %lld\n",ti,q);
        else
            printf("Case %d: %lld/%lld\n",ti,q,P);
    }
    return 0;
}
