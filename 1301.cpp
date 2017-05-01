#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<pii> v;

bool cmp(pii a,pii b)
{
    return (a.first<b.first) || (a.first==b.first && a.second<b.second);
}

int main()
{
    int n,t,ti,i,j,k,ans,maxi;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        v.clear();
        for(i=0; i<n; ++i)
        {
            scanf("%d %d",&j,&k);
            v.push_back(make_pair(j,0));
            v.push_back(make_pair(k,1));
        }
        sort(v.begin(),v.end(),cmp);
        ans=0;
        maxi=0;
        for(i=0; i<v.size(); ++i)
        {
            if(v[i].second==0)
                ++ans;
            else
                --ans;
            maxi=max(maxi,ans);
        }
        printf("Case %d: %d\n",ti,maxi);
    }
    return 0;
}
