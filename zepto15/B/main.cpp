#include <iostream>

using namespace std;
int n;
int res;
int A[100000];
int dfs(int u)
{
    if(u>((1<<n)-1))
        return A[u];


    int lval = dfs(u*2);
    int rval = dfs(u*2+1);
    if(lval > rval)
    {
        res+=(lval-rval);
        return lval+A[u];

    }
    else
    {
        res+=(rval-lval);
        return rval+A[u];
    }
}
int main()
{
    cin>>n;
    res = 0;
    for(int i=2;i<=((1<<(n+1))-1);++i)
        cin>>A[i];
    dfs(1);
    cout<<res;
}
