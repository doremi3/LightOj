#include<bits/stdc++.h>
using namespace std;

vector<int> a,b;
queue<int>q;

int main()
{
    int t,ti,i,j,k,n,ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        ans=0;
        a.clear();
        b.clear();
        while(!q.empty())
            q.pop();
        for(i=0; i<n; ++i)
        {
            scanf("%d",&j);
            a.push_back(j);
        }
        for(i=0; i<n; ++i)
        {
            scanf("%d",&j);
            b.push_back(j);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        i=j=0;
        for(i=0; i<n; ++i)
        {
            if(b[j]<a[i])
            {
                ans+=2;
                j++;
            }
            else
            {
                if(!q.empty() && q.front()<a[i])
                {
                    q.pop();
                    ans+=2;

                }
                else if(a[i]==b[j])
                {
                    q.push(a[i]);
                    ++j;
                }
            }
        }
        ans+=q.size();
        printf("Case %d: %d\n",ti,ans);
    }
    return 0;
}
