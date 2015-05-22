#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll lcm;
struct hit{
    ll num,den;
    char a;
    bool operator<(const hit &x) const
    {
        if(*this == x)
            return a<x.a;
        ll numc = (lcm/den)*num;
        ll numx = (lcm/x.den)*x.num;
        return numc<numx;


    }
    bool operator==(const hit &x) const
    {
        ll numc = (lcm/den)*num;
        ll numx = (lcm/x.den)*x.num;
        return numc==numx;
    }
    bool operator!=(const hit &x) const
    {
        return !(*this==x);
    }

};
vector<hit> A;
int main()
{

    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    lcm = (1ll*x*y)/__gcd(x,y);
    for(int i=1;i<=x;++i)
    {
        hit tmp;
        tmp.num = i;
        tmp.den = x;
        tmp.a = 'A';
        A.push_back(tmp);

    }
    for(int i=1;i<=y;++i)
    {
        hit tmp;
        tmp.num = i;
        tmp.den = y;
        tmp.a='V';
        A.push_back(tmp);


    }
    sort(A.begin(),A.end());
    for(int i=1;i<=n;++i)
    {
        int ai;
        scanf("%d",&ai);
        ai%=(x+y);
        if(ai == 0)
        {
            printf("Both\n");
            continue;
        }
        hit x = A[ai-1];
        if(x.a=='A')
        {
            hit y = A[ai];
            if(y!=x)
                printf("Vanya\n");
            else
                printf("Both\n");

        }
        else
        {
            if(ai-2 <0 || A[ai-2]!=x)
                printf("Vova\n");
            else
                printf("Both\n");

        }





    }



}
