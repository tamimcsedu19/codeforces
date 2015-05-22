#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sugard[105],sugarc[105];
int n,s;
int main()
{
    cin>>n>>s;
    int maxcent=0;
    bool buy=0;
    for(int i=1;i<=n;++i)
    {
        int d,c;

        cin>>d>>c;
        int price = c==0 ? d:d+1;

        if(price<=s)
        {
            buy = true;
            maxcent = max(100-c == 100?0:100-c ,maxcent);

        }

    }
    if(buy)
        cout<<maxcent<<"\n";
    else
        cout<<-1;


}
