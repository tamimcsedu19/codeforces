#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin>>n;
    ll max_x=INT_MIN,max_y=INT_MIN,min_x=INT_MAX,min_y=INT_MAX;
    for(int i=0;i<n;++i)
    {
        ll x,y;
        cin>>x>>y;
        max_x = max(max_x,x);
        max_y = max(max_y,y);
        min_x = min(min_x,x);
        min_y = min(min_y,y);

    }

    ll res = max(abs(max_x-min_x),abs(max_y-min_y));
    cout<<res*res;

}
