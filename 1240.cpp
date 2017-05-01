#include<bits/stdc++.h>
using namespace std;

struct point{
    double x,y,z;
};

typedef point point;

point a,b,p;

double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z) );
}

double ternary()
{
    point lo,hi,mid1,mid2;
    double d1,d2;
    int i;
    lo=a;
    hi=b;
    for(i=0; i<100; ++i)
    {
        mid1.x=(2*lo.x+hi.x)/3;
        mid1.y=(2*lo.y+hi.y)/3;
        mid1.z=(2*lo.z+hi.z)/3;
        d1=dist(p,mid1);
        mid2.x=(lo.x + 2*hi.x)/3;
        mid2.y=(lo.y + 2*hi.y)/3;
        mid2.z=(lo.z + 2*hi.z)/3;
        d2=dist(p,mid2);
        if(d1<d2)
            hi=mid2;
        else
            lo=mid1;
    }
    return min(d1,d2);
}

int main()
{
    int t,ti;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lf %lf %lf",&a.x,&a.y,&a.z);
        scanf("%lf %lf %lf",&b.x,&b.y,&b.z);
        scanf("%lf %lf %lf",&p.x,&p.y,&p.z);
        printf("Case %d: %.8lf\n",ti,ternary());
    }
    return 0;
}
