#include <iostream>
#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
int bit[maxn],A[maxn],l[maxn];
void update(int x,int val)
{
    while(x<maxn)
    {
        bit[x]+=val;
        x+=(x&-x);
    }
}
ll ask(int x)
{
    ll sum = 0;
    if(x<=0)
        return 0;
    while(x)
    {
        sum+=bit[x];
        x-=(x&-x);

    }
    return sum;

}
map<int,int> f;

int main()
{


    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>A[i];
        ++f[A[i]];
        l[i] = f[A[i]];

    }
    f.clear();
    ll res = 0;
    for(int i=n;i>=1;--i)
    {
        res+=ask(l[i]-1);
        ++f[A[i]];
        update(f[A[i]],1);
    }
    cout<<res<<endl;




}
