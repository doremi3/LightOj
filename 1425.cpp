#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    int ans,t,ti,i,j,k,n;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        v.clear();
        scanf("%d",&n);
        v.push_back(0);
        for(i=1; i<=n; ++i)
        {
            scanf("%d",&j);
            v.push_back(j);
        }
        ans=0;
        for(i=n-1; i>=0; --i)
        {
            if(v[i+1]-v[i]>ans)
                ans=v[i+1]-v[i];
            else if(v[i+1]-v[i]==ans)
                ans++;
        }
        printf("Case %d: %d\n",ti,ans);
    }
    return 0;
}
