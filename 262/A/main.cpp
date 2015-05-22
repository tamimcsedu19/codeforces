#include <iostream>
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int A[maxn];


int main()
{

    int n,m;
    cin>>n>>m;
    int sz = 0;
    for(int i=1;i<=n;++i)
    {
        if(i%m == 0)
            ++n;

    }
    cout<<n;


}
