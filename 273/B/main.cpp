#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    if(n==m)
    {
        cout<<0<<" "<<0;
        return 0;
    }
    if(m == 1)
    {
        cout<<(n*(n-1))/2<<" "<<(n*(n-1))/2;
        return 0;
    }

    ll min_n = n/m;

    ll kminv = (min_n*(min_n-1))/2;
    kminv*=(m-1);
    ll r = n-min_n*(m-1);
    kminv+=(r*(r-1))/2;
    ll maxn = n-m+1;
    ll kmax = (maxn*(maxn-1))/2;
    if(kminv>kmax)
        swap(kminv,kmax);
    cout<<kminv<<" "<<kmax;


}
