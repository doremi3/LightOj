#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans,t,ti,r,c,i,j,k;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d",&r,&c);
        ans=0;
        for(i=1; i<=r; ++i)
        {
            for(j=1; j<=c; ++j)
            {
                scanf("%d",&k);
                if((r-i+c-j)%2)
                    ans=ans^k;

            }
        }
        if(ans)
            printf("Case %d: win\n",ti);
        else
            printf("Case %d: lose\n",ti);
    }
    return 0;
}
