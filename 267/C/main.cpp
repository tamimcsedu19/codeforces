#include <iostream>

using namespace std;
typedef long long int ll;
ll csum[5005];
ll dp[5005][5005];
ll A[5005];
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<5001;++i)
        for(int j=0;j<5001;++j)
            dp[i][j] = 0;
    A[0] = 0;
    for(ll i=1;i<=n;++i)
    {
        cin>>A[i];
        csum[i] = (csum[i-1]+A[i]);
    }
    for(ll i=1;i<=k;++i)
    {
        for(ll j=(i-1)*m+1; j<=(n-m+1);++j)
            dp[i][j+m-1] = max(dp[i][j+m-2],dp[i-1][j-1]+(csum[j+m-1]-csum[j-1]));
    }

    ll maxv = 0;
    for(int i=1;i<=n;++i)
        maxv = max(dp[k][i],maxv);
    cout<<maxv;



}
