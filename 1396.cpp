#include<bits/stdc++.h>
using namespace std;

char s[100010],pre[100010];

int main()
{
    int t,ti,l,i,j,k,n,ans,f;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%s",s);
        strcpy(pre,s);
        l=strlen(s);
        f=0;
        for(i=0,j=l-1; i<=j; ++i, --j)
        {
            s[j]=s[i];
        }
        --i;
        ++j;
        if(strcmp(s,pre)<=0)
        {
            while(i>=0)
            {
                if(s[i]<'9')
                    break;
                s[i]=s[j]='0';
                --i;
                ++j;
            }
            if(i>=0)
            {
                s[i]=s[j]=s[i]+1;
            }
            else{
                f=1;
                s[l-1]='1';
            }
        }
        if(f==0)
            printf("Case %d: %s\n",ti,s);
        else
            printf("Case %d: 1%s\n",ti,s);
    }
    return 0;
}
