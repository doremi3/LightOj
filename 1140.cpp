#include<bits/stdc++.h>
using namespace std;

#define MAX 15
#define MOD
typedef long long ll;

char s[MAX],l;
ll p[MAX];
ll dp[MAX][2][2];

ll cal(int i, int sm, int num)
{
    if(i==l)
        return 0;
    if(dp[i][sm][num] != -1)
        return dp[i][sm][num];
    ll ret1,ret2;
    ret1=ret2=0;
    if(sm)
    {
        if(num)
            ret1=(p[l-i-1]+((ll)(10)*cal(i+1,sm,num)));
        else
        {
            ret1=cal(i+1,sm,0);
            ret2=9*cal(i+1,sm,1);
        }
    }
    else
    {
        if(num)
        {
            if(s[i]=='0')
            {
                for(int j=i+1; j<l; ++j)
                    ret1=(ret1*(ll)10)+s[j]-'0';
                ret1++;
                ret1+=(cal(i+1,0,num));
            }
            else
            {
                ret1=(p[l-i-1]+cal(i+1,1,num)*(s[i]-'0') );
                ret2=cal(i+1,0,num);
            }
        }
        else
        {
            if(s[i]=='0')
            {
                ret1=cal(i+1,0,0);
            }
            else
            {
                ret1=cal(i+1,1,0);
                if(s[i]>'1')
                 ret1+=(cal(i+1,1,1)*(s[i]-'0'-1)) ;
                ret2=cal(i+1,0,1);
            }
        }
    }
   // printf("%d %d %d %lld\n",i,sm,num,ret1+ret2);
    return dp[i][sm][num]=(ret1+ret2);
}

int main()
{
    int t,ti,mp,np,f,i;
    ll a,b,ans,na,nb;
    p[0]=1;
    for(t=1; t<MAX; ++t)
        p[t]=p[t-1]*(ll)(10);
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        a=b=0;
        na=nb=0;
        scanf("%s",s);
        l=strlen(s);
        for(i=0; i<l; ++i)
        {
            if(s[i]=='0')
                ++na;
        }
        if(s[0]=='-')
        {
            s[0]='0';
            mp=-1;
        }
        else if(l==1 && s[0]=='0')
        {
            mp=0;
        }
        else
            mp=1;
        memset(dp,-1,sizeof(dp));
        if(mp)
            a=cal(0,0,0);
        scanf("%s",s);
        l=strlen(s);
        for(i=0; i<l; ++i)
        {
            if(s[i]=='0')
                ++nb;
        }
        if(s[0]=='-')
        {
            s[0]='0';
            np=-1;
        }
        else if(l==1 && s[0]=='0')
        {
            np=0;
        }
        else
            np=1;
        memset(dp,-1,sizeof(dp));
        if(np)
            b=cal(0,0,0);
        if(mp>=0 && np>=0)
        {
            ans=b-a+na;

        }
        else if(mp<=0 && np<=0)
        {
            ans=a-b+nb;


        }
        else if(mp<0 && np>0)
        {
            ans=a+b+1;
        }
        if(mp==0 && np==0)
            ans=1;
        printf("Case %d: %lld\n",ti,ans);
    }
    return 0;
}
