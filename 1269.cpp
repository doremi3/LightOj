#include<bits/stdc++.h>
using namespace std;

#define MAX 3


char s[40];

int a[60000];

struct node{
    bool leaf;
    struct node *edge[MAX];

    node()
    {
        int i;
        leaf=0;
        for(i=0; i<MAX; ++i)
            edge[i]=NULL;
    }

};

typedef struct node node;

node *root;

void add(char s[], int l)
{
    int i,j;
    bool f1,f2;
    node *curr=root;
    f1=0;
    f2=1;
    for(i=0; i<l; ++i)
    {
        j=s[i]-'0';
        if(curr->edge[j]==NULL){
            curr->edge[j]=new node();
        }
        curr=curr->edge[j];
    }
    curr->leaf=1;
}

int fndmax(char s[])
{
    int i,l,j;
    int ret=0;
    node *curr=root;
    l=strlen(s);
    for(i=0; i<l; ++i)
    {
        j=(s[i]-'0');
        if(curr->edge[1-j]!=NULL)
        {
            ret=(ret*2)+1;
             curr=curr->edge[1-j];
        }
        else
        {
            ret=ret*2;
            curr=curr->edge[j];
        }
    }
    return ret;
}

int fndmin(char s[])
{
    int i,l,j;
    int ret=0;
    node *curr=root;
    l=strlen(s);
    for(i=0; i<l; ++i)
    {
        j=(s[i]-'0');
        if(curr->edge[j]!=NULL)
        {
            ret=(ret*2);
             curr=curr->edge[j];
        }
        else
        {
            ret=(ret*2)+1;
            curr=curr->edge[1-j];
        }
    }
    return ret;
}

void del(node *curr)
{
    int i;
    if(curr==NULL)
        return ;
    for(i=0; i<MAX; ++i)
    {
        del(curr->edge[i]);
    }
    delete(curr);
}

void toStr(int num, char str[40])
{
    int m,l,j,i=0;
    m=num;
    while(m)
    {
        str[i++]=(m%2)+'0';
        m/=2;
    }
    while(i<35)
        str[i++]='0';
    str[i]=0;
    l=i;
    for(i=0,j=l-1; i<j; ++i,--j)
        swap(str[i],str[j]);

}

int main()
{
    int t,ti,n,i,j,k,maxi,mini;
    bool flag;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        root=new node();
        scanf("%d",&n);
        for(i=0; i<n; ++i)
            scanf("%d",&a[i]);
        for(i=1; i<n; ++i)
            a[i]=a[i]^a[i-1];
        toStr(a[0],s);
        add(s,strlen(s));
        maxi=mini=a[0];
        for(i=1; i<n; ++i)
        {
            toStr(a[i],s);
            maxi=max(maxi,a[i]);
            maxi=max(maxi,fndmax(s));
            mini=min(mini,a[i]);
            mini=min(mini,fndmin(s));
            add(s,strlen(s));
        }
        del(root);
        printf("Case %d: %d %d\n",ti,maxi,mini);
    }
    return 0;
}

