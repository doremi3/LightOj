#include<bits/stdc++.h>
using namespace std;

#define MAX 15


char s[15];

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

bool add(char s[])
{
    int i,l,j;
    bool f1,f2;
    node *curr=root;
    l=strlen(s);
    f1=0;
    f2=1;
    for(i=0; i<l; ++i)
    {
        if(curr->leaf==1)
            f1=1;
        j=s[i]-'0';
        if(curr->edge[j]==NULL){
            f2=0;
            curr->edge[j]=new node();
        }
        curr=curr->edge[j];
    }
    curr->leaf=1;
    return f1|f2;
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

int main()
{
    int t,ti,n,i,j,k;
    bool flag;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        root=new node();
        flag=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",s);
            if(add(s))
                flag=1;
        }
        if(flag)
            printf("Case %d: NO\n",ti);
        else
            printf("Case %d: YES\n",ti);
        del(root);
    }
    return 0;
}
