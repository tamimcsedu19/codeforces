#include <bits/stdc++.h>
#define maxn 100005
typedef long long ll;
using namespace std;

const ll MOD = 1000000007;
ll dp[2][maxn];
bool col[maxn];
vector<int> G[maxn];
void dfs(int u,int p)
{
    dp[0][u] = !col[u];
    dp[1][u] = col[u];
    for(int v:G[u]) if(v!=p)
    {
        ll prev0 = dp[0][u];
        ll prev1 = dp[1][u];
        dp[0][u] = dp[1][u] = 0;
        dfs(v,u);

        dp[0][u] += (dp[0][v]*prev0);
        dp[0][u]%=MOD;
        dp[0][u] += (dp[1][v]*prev0);
        dp[0][u]%=MOD;
        dp[1][u] += (dp[1][v]*prev0);
        dp[1][u]%=MOD;
        dp[1][u] += (dp[0][v]*prev1);
        dp[1][u]%=MOD;
        dp[1][u] += (dp[1][v]*prev1);
        dp[1][u]%=MOD;

    }

}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int v;
        cin>>v;
        G[i].push_back(v);
        G[v].push_back(i);

    }
    for(int i=0;i<n;++i)
        cin>>col[i];
    dfs(0,-1);
    cout<<dp[1][0];


}
