#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long int> A;
int main()
{
    long long int n;
    cin>>n;
    for(long long int i=0;i<n;++i)
    {
        long long int x;
        cin>>x;
        A.push_back(x);
    }
    sort(A.begin(),A.end());
    long long int i=0,j=A.size()-1;
    while(i<(n-1) && A[i+1] == A[i]) ++i;
    while(j>0 && A[j-1] == A[j]) --j;
    if(j<=i)
    {
        cout<<0<<" "<<(n*(n-1))/2<<endl;
    }
    else
    {
        cout<<(A[A.size()-1]-A[0])<<" "<<(i+1)*(n-j)<<endl;

    }


}
