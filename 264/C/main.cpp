#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[2005][2005];
ll sums[4][2005][2005];


ll n;
int main()
{
    memset(sums,0,sizeof sums);

    scanf("%I64d",&n);

    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j)
        {
            scanf("%I64d",&A[i][j]);
            for(ll k=0;k<4;++k)
                sums[k][i][j] = A[i][j];
        }

    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j)
        {
            sums[0][i][j]+=sums[0][i-1][j-1];
            sums[1][i][j]+=sums[1][i-1][j+1];

        }
    for(ll i=n;i>=1;--i)
        for(ll j=n;j>=1;--j)
        {
            sums[2][i][j]+=sums[2][i+1][j-1];
            sums[3][i][j]+=sums[3][i+1][j+1];

        }
    pair<int,int> bishops[2];


    ll sum[2]={-1,-1};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll sumc = 0;
            for(ll k=0;k<4;++k)
                sumc+=sums[k][i][j];
            sumc-=(3ll*A[i][j]);

            int c = ((i+j)&1);
            if(sum[c] < sumc)
            {
                sum[c] = sumc;
                bishops[c] ={i,j};
            }

        }

    }
    printf("%I64d\n",sum[0]+sum[1]);
    printf("%d %d %d %d",bishops[0].first,bishops[0].second,bishops[1].first,bishops[1].second);

}
