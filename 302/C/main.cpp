#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int A[502],n,m;
int b,mod;
ll dpt[502][502];
int main()
{

    memset(dpt,0,sizeof dpt);
    cin>>n>>m>>b>>mod;
    for(int i=1;i<=n;++i)
        cin>>A[i];

    dpt[0][0] = 1;
    for(int i=1;i<=n;++i)
    {
        for(int line = 1;line<=m;++line)
        {
            for(int bugs = A[i];bugs<=(b);++bugs)
            {
                dpt[line][bugs]=(dpt[line][bugs]+dpt[line-1][bugs-A[i]])%mod;



            }

        }



    }
    int res = 0;
    for(int i=0;i<=b;++i)
        res=(res+dpt[m][i])%mod;
    cout<<res<<endl;

}
