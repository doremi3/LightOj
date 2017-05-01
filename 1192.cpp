#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,i,ans,t,ti,g,w;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&k);
        ans=0;
        for(i=0; i<k; ++i)
        {
            scanf("%d %d",&g, &w);
            ans=ans^(w-g-1);
        }
        if(ans)
            printf("Case %d: Alice\n",ti);
        else
            printf("Case %d: Bob\n",ti);
    }
    return 0;
}
