#include <iostream>
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
vector<long long int> A;
int main()
{
    long long int sum = 0;
    long long int n;
    cin>>n;
    while(n--)
    {
        long long int x;
        cin>>x;
        A.push_back(x);
        sum+=x;

    }
    sort(A.begin(),A.end());
    long long int res1 = sum;
    for(long long int i=0;i<A.size();++i)
    {
        res1+=A[i];
        res1+=(sum-A[i]);
        sum-=A[i];


    }
    long long int res2 = sum;
    for(long long int i=A.size()-1;i>=0;--i)
    {
        res2+=A[i];
        res2+=(sum-A[i]);
        sum-=A[i];


    }


    cout<<max(res1-A[A.size()-1],res2-A[0])<<endl;
}
