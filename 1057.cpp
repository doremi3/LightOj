#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

vector<pii> v;

int dp[100000][17];
int m,n,s;

int dis(pii a, pii b)
{
    int x,y;
    x=a.first-b.first;
    if(x<0)
        x*=-1;
    y=a.second - b.second;
    if(y<0)
        y*=-1;
    return max(x,y);

}

bool check(int a,int p)
{
    return a&(1<<p);
}


int set(int a,int p)
{
    return a|(1<<p);
}

int cal(int mask, int pre,int total)
{
    if(total==s)
        return dis(v[pre],v[v.size()-1]);
    if(dp[mask][pre] !=-1)
        return dp[mask][pre];
    int i,j,ret=9999999;
    for(i=0; i<s; ++i)
    {
        if(!check(mask,i))
        {
            ret=min(ret, cal(set(mask,i),i,total+1) + dis(v[pre],v[i]));
        }
    }
    return dp[mask][pre]=ret;

}

int main()
{
    int t,ti,i,j,k,l;
    pii a;
    char str[30];
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        v.clear();
        s=0;
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&m,&n);
        for(i=0; i<m; ++i)
        {
            scanf("%s",str);
            l=strlen(str);
            for(j=0; j<l ; ++j)
            {
                if(str[j]=='g'){
                    v.push_back(make_pair(i,j));
                }
                else if(str[j]=='x')
                {
                    a.first=i;
                    a.second=j;
                }

            }
        }
        s=v.size();
        v.push_back(a);
        printf("Case %d: %d\n",ti,cal(0,v.size()-1,0));
    }
    return 0;
}


