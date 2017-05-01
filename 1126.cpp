#include<bits/stdc++.h>
using namespace std;


int dp[250005];
int n,h[55];

int main()
{
    int t,ti,i,j,k;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        k=0;
        for(i=0; i<n; ++i)
        {
            scanf("%d",&h[i]);
            k+=h[i];
        }

        if(i>=1)
            printf("Case %d: %d\n",ti,i);
        else
            printf("Case %d: impossible\n",ti);
    }
    return 0;
}
