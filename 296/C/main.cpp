#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
set<int> sx,sy;
set<pair<int,ii> > maxX;
set<pair<int,ii>> maxY;

typedef long long int ll;

int main()
{
    int w,h;
    cin>>w>>h;
    sx.insert(0);
    sy.insert(0);
    sx.insert(w);
    sy.insert(h);
    maxX.insert({w,{0,w}});
    maxY.insert({h,{0,h}});
    int n; cin>>n;
    while(n--)
    {
        char c; cin>>c;
        int cut; cin>>cut;
        if(c == 'H')
        {
            auto l=sy.upper_bound(cut);
            auto u = l--;
            sy.insert(cut);
            maxY.erase({(*u)-(*l),{*l,*u}});
            maxY.insert({(cut-*l),{*l,cut}});
            maxY.insert({(*u-cut),{cut,*u}});
        }
        else
        {
            auto l=sx.upper_bound(cut);
            auto u = l--;
            sx.insert(cut);
            maxX.erase({(*u)-(*l),{*l,*u}});
            maxX.insert({(cut-*l),{*l,cut}});
            maxX.insert({(*u-cut),{cut,*u}});
        }

        ll x = (--maxX.end())->first;
        ll y = (--maxY.end())->first;
        cout<<x*y<<"\n";

    }



}
