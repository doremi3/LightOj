#include<stdio.h>
#include<algorithm>
#include<stack>
#include<string.h>

using namespace std;

#define MAX 2003

pair <int,int> item;

stack < pair <int,int> > st; //h,ind

int left[MAX],right[MAX],h[MAX],n,a[MAX],m;
char s[MAX];
void findleft()
{
    int i;
    memset(left,-1,sizeof(left));
    while(st.size()>0)
        st.pop();
    st.push(make_pair(h[0],0));
    left[0]=0;
    for(i=1; i<n; ++i)
    {
        while(st.size()>0)
        {
            if(st.top().first < h[i])
                break;
            st.pop();
        }
        if(st.size()==0)
            left[i]=0;
        else
            left[i]=st.top().second+1;
        st.push(make_pair(h[i],i));
    }
}

void findright()
{
    int i;
    memset(right,-1,sizeof(right));
    while(st.size()>0)
        st.pop();
    st.push(make_pair(h[n-1],n-1));
    right[n-1]=n-1;
    for(i=n-2; i>=0; --i)
    {
        while(st.size()>0)
        {
            if(st.top().first < h[i])
                break;
            st.pop();
        }
        if(st.size()==0)
            right[i]=n-1;
        else
            right[i]=st.top().second-1;
        st.push(make_pair(h[i],i));
    }
}

int main()
{
    int t,ti,i,maxi,j;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d",&m,&n);
        maxi=0;
        memset(h,0,sizeof(h));
        for(j=0; j<m; ++j)
        {
            scanf("%s",s);
            for(i=0; i<n; ++i)
            {
                if(s[i]=='0')
                    a[i]=1;
                else
                    a[i]=0;
                if(a[i]==0)
                    h[i]=0;
                else
                    h[i]=h[i]+1;
            }
            findleft();
            findright();
            for(i=0; i<n; ++i)
            {
                if((right[i]-left[i]+1)*h[i]>maxi)
                    maxi=(right[i]-left[i]+1)*h[i];
            }
        }
        printf("Case %d: %d\n",ti,maxi);
    }
    return 0;
}
