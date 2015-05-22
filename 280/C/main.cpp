#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
ll A[100005],B[100005];
ll n,avg,r;
bool isPoss(ll numOfEssay)
{
    vector<ii> tmp;
    for(int i=1;i<=n;++i)
        tmp.push_back({B[i],A[i]});
    sort(tmp.begin(),tmp.end());

    for(ii &x:tmp)
    {
        if(numOfEssay == 0)
            break;
        ll needToWrite = numOfEssay/x.first;

        ll canWrite = min(needToWrite,r-x.second);
        numOfEssay-=(canWrite*x.first);
        x.second+=canWrite;


    }
    ll sum = 0;
    for(ii x:tmp)
        sum+=x.second;

    sum/=n;
    return sum>=avg;
}


int main()
{
    cin>>n>>r>>avg;
    for(int i=1;i<=n;++i)
        cin>>A[i]>>B[i];
    ll lo=0,hi=1e+18;
    while(lo<hi)
    {
        ll mid = (lo+hi)/2;
        if(isPoss(mid))
            hi = mid;
        else
            lo = mid+1;


    }

    cout<<lo<<endl;



}
