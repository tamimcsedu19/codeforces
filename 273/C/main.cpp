#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll bin_search(ll x,ll y)
{
    if(2*y == x)
        return y;
    ll lo = 0 , hi = y,mid;
    while(lo<hi)
    {
        mid = (lo+hi)/2;
        if(2*mid<x)
            lo=mid+1;
        else
            hi = mid-1;


    }
    return mid;



}
int main()
{
    vector<int> rgb;
    for(int i=0;i<3;++i)
    {
        int x;
        cin>>x;
        rgb.push_back(x);
    }
    sort(rgb.begin(),rgb.end());
    ll ans = rgb[0];
    ll x = rgb[2]-rgb[0];
    ll y = rgb[1]-rgb[0];
   while((2*y)>x)
    --y;
    cout<<ans+y;




}
