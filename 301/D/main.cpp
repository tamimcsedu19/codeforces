#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double dpR(int r,int s,int p)
{
    if(p == 0)
    {
        return 1.0;
    }
    else if(s == 0 || r == 0)
        return 0.0;
    double m1 = ()
    double p1 = dpR(r,s-1,p);
    double m2 = ((r*1.0)/(r*1.0+s+p))*((p*1.0)/(r*1.0+s+p-1));
    double p2 = dpR(r-1,s,p);
    double m3 = ((s*1.0)/(r*1.0+s+p))*((p*1.0)/(r*1.0+s+p-1));
    double p3 = dpR(r,s,p-1);
    return m1*p1+m2*p2+m3*p3;




}
int main()
{
    cout<<dpR(2,1,2)<<endl;

}
