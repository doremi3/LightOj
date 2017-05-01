#include<bits/stdc++.h>
using namespace std;

struct point{

    double x,y;
}a,b,c,d;

typedef struct point point;

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

point mratio(point a, point b, double m)
{
    double m1,m2;
    m1=m;
    m2=1-m;
    point c;
    c.x=(a.x*m2+b.x*m1);
    c.y=(a.y*m2+b.y*m1);
    return c;
}

double ternary()
{
    int i;
    double lo,hi,m1,m2,d1,d2;
    point ab,cd;
    lo=0;
    hi=1;
    for(i=0; i<100; ++i)
    {
        m1=(2*lo+hi)/3;
        ab=mratio(a,b,m1);
        cd=mratio(c,d,m1);
        d1=dist(ab,cd);
        m2=(lo+2*hi)/3;
        ab=mratio(a,b,m2);
        cd=mratio(c,d,m2);
        d2=dist(ab,cd);
        if(d1<d2)
            hi=m2;
        else
            lo=m1;


    }
    return min(d1,d2);
}

int main()
{
    int t,ti;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x, &b.y);
        scanf("%lf %lf %lf %lf",&c.x,&c.y,&d.x, &d.y);
        printf("Case %d: %.8lf\n",ti,ternary());
    }
    return 0;
}
