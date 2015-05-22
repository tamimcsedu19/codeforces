#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll mod = 1000000007;

int main()
{
    ll sum = 0,a,b;
    cin>>a>>b;
    ll constv =(b*(b-1))/2;
    constv%=mod;
    for(int k=1;k<=a;++k)
    {

        ll curr = (k*b+1);
        curr%=mod;
        ll tmpsum = (curr*constv)%mod;
        sum = (tmpsum+sum)%mod;


    }
    cout<<sum;


}
