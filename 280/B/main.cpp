#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;
int main()
{
    vector<ll> A;
    ll n,l;
    cin>>n>>l;


    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }

    sort(A.begin(),A.end());

    ld maxv = (long double)A[0];
    for(int i=1;i<A.size();++i)
    {
        ld tmp = (long double)((A[i]-A[i-1])/2.0);
        maxv = max(maxv,tmp);


    }
    maxv = max(maxv,(long double)(l-A[A.size()-1]));
    cout<<maxv<<endl;






}
