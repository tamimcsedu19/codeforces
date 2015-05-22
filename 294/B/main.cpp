#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> A,B,C;
int main()
{
    int n; cin>>n;
    for(int i=0;i<n;++i)
    {
        int x; cin>>x; A.push_back(x);
    }
    for(int i=0;i<n-1;++i)
    {
        int x; cin>>x; B.push_back(x);
    }
    for(int i=0;i<n-2;++i)
    {
        int x; cin>>x; C.push_back(x);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    vector<int> v(1);
    std::set_difference (A.begin(), A.end(), B.begin(), B.end(), v.begin());

    cout<<v[0]<<"\n";

    std::set_difference (B.begin(), B.end(), C.begin(), C.end(), v.begin());
    cout<<v[0];
}
