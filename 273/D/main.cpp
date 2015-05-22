#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef pair<int,int> ii;
typedef pair<bool,ll> bl;

map<pair<ii,int> ,bl> dpt;
const ll mod = 1000000007;
int h;

pair<bool,ll> dp(int height,int r,int g)
{
    if(r<0 || g<0)
        return {0,0};
    if(height == 0)
        return {1,1};
    ll tmp = (height*(height+1))/2;
    if(r+g < tmp)
        return {0,0};
    auto f = dpt.find({{height,r},g});
    if(f!=dpt.end())
        return f->second;

    bl x = dp(height-1,r-height,g),y=dp(height-1,r,g-height);
    return {x.first || y.first,(x.second+y.second)%mod};
}

int main()
{

    ll r,g;
    cin>>r>>g;
    for(h = 2*317;h>=1;--h)
    {
        if(((h*(h+1))/2)<=(r+g))
        {
            auto x = dp(h,r,g);
            if(x.first)
            {
                cout<<x.second;
                return 0;

            }

        }





    }

}
