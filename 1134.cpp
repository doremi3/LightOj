#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

long long a[MAX],cnt[MAX];

int main()
{
    long long t,ti,i,j,k,n,m,curr,ans;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld",&n,&m);
        for(i=1; i<=n; ++i)
            scanf("%lld",&a[i]);
        memset(cnt,0,sizeof(cnt));
        cnt[0]=1;
        curr=ans=0;
        for(i=1; i<=n; ++i)
        {
            curr=(curr+a[i])%m;
            ans+=cnt[curr];
            cnt[curr]++;
        }
        printf("Case %lld: %lld\n",ti,ans);

    }
    return 0;
}
