#include<bits/stdc++.h>
using namespace std;

char s[15],a[15],b[15];

int l,k,dp[12][95][95][2];

int cal(int i, int m1,int m2, bool sm) // m1=sum%mod
{
   // printf("%d %d %d %d\n",i,m1,m2,sm);
    if(i==l)
        return ((m1==0)&&(m2==0));
    if(dp[i][m1][m2][sm] != -1)
        return dp[i][m1][m2][sm];
    int c,ret;
    ret=0;
    for(c=0; c<s[i]-'0'; ++c)
        ret+=cal(i+1,(m1+c)%k, ((m2*10)+c)%k, 1);
    c=s[i]-'0';
    ret+=cal(i+1,(m1+c)%k, ((m2*10)+c)%k, sm);
    if(sm)
    {
        for(c=s[i]-'0'+1; c<=9; ++c)
            ret+=cal(i+1,(m1+c)%k, ((m2*10)+c)%k, 1);
    }
    return dp[i][m1][m2][sm]=ret;
}

int main()
{
    int t,ti,na,nb,temp,m1,m2,ans,i;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%s %s %d",a,b,&k);
        ans=0;
        if(k<=90)
        {

            na=nb=m1=m2=0;
            l=strlen(a);
           // puts(a);
            for(i=0; i<l; ++i)
            {
                m1=(m1+a[i]-'0')%k;
                m2=((m2*10)+a[i]-'0')%k;
            }
            strcpy(s,a);
            l=strlen(s);
            memset(dp,-1,sizeof(dp));
            na+=cal(0,0,0,0);
            strcpy(s,b);
            l=strlen(s);
            memset(dp,-1,sizeof(dp));
            nb+=cal(0,0,0,0);
            ans=nb-na;
            if(m1==0 && m2==0)
                ++ans;
        }
        printf("Case %d: %d\n",ti,ans);
    }
    return 0;
}
