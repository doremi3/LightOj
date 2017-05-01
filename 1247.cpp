#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,ti,n,m,i,j,k,ans,curr;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld",&m,&n);
        ans=0;
        while(m--)
        {
            curr=0;
            for(i=0; i<n; ++i)
            {
                scanf("%lld",&k);
                curr+=k;
            }
            ans=ans^curr;
        }
        if(ans)
            printf("Case %d: Alice\n",ti);
        else
            printf("Case %d: Bob\n",ti);
    }
    return 0;
}
