#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 10000

typedef long long ll;

vector <ll> d[MAX+5],a;

long long flag[MAX+5],cnt[MAX+5],c[MAX+5][4];
ll dis[MAX+5],one,two,three,four;

void seive()
{
    long long i,j;
    flag[1]=1;
    for(i=2; i<=MAX; ++i)
    {
        d[i].push_back(i);
        if(!flag[i])
            cnt[i]++;
        for(j=i+i; j<=MAX; j+=i)
        {
            flag[j]=1;
            d[j].push_back(i);
            if(!flag[i])
            {
                cnt[j]++;
            }
        }
    }
}
int main()
{
    long long t,ti,n,i,j,k,ans;
    seive();
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        memset(c,0,sizeof(c));
        memset(dis,0,sizeof(dis));
        a.clear();
        one=two=three=four=0;
        ans=0;
        scanf("%lld",&n);
        for(i=0; i<n; ++i)
        {
            scanf("%lld",&k);
            dis[k]++;
            if(dis[k]==1)
            {
                a.push_back(k);
                one++;
            }
            else if(dis[k]==2)
                two++;
            else if(dis[k]==3)
                three++;
            else if(dis[k]==4)
                four++;
        }
        for(i=0; i<a.size(); ++i)
        {
            j=a[i];
            for(k=0; k<d[j].size(); ++k)
            {
                if(dis[j]>=1)
                    ++c[d[j][k]][0];
                if(dis[j]>=2)
                    ++c[d[j][k]][1];
                if(dis[j]>=3)
                    ++c[d[j][k]][2];
                if(dis[j]>=4)
                    ++c[d[j][k]][3];
            }
        }
        for(i=2; i<=MAX; ++i)
        {
            if((cnt[i]==1 && flag[i]))
                continue;
            j=c[i][3] + max((ll)0,c[i][2]*(c[i][0]-1)) + max((ll)0, c[i][1]*(c[i][1]-1)) + max((ll)0, c[i][1]*(c[i][0]-1)) ;
            j = j+ max((ll)0, (c[i][0] *(c[i][0]-1)*(c[i][0]-2)*(c[i][0]-3))/24);

            if(j<0)
                j=0;
            if(cnt[i]&1)
                ans+=j;
            else
                ans-=j;
        }

        if(ans<0)
            ans=0;
        j = four + max((ll)0,three *(one-1)) + max(two*(two-1),(ll)0) + max(two * (one-1),(ll)0) + max((ll)0, (one*(one-1)*(one-2)*(one-3))/24);
        ans=j-ans;
        printf("Case %lld: %lld\n",ti,ans);
    }
    return 0;
}
