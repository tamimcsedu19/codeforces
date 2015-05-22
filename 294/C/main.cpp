#include <iostream>

using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    int maxTeam = 0;
    for(int i=0;i<=n;++i)
    {
        int experiencedRemaining = n-i;
        int beginnerRemaining = m-2*i;
        int teams = min(experiencedRemaining/2,beginnerRemaining);
        maxTeam = max(i+teams , maxTeam);
    }
    cout<<maxTeam;

}
