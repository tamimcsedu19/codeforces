#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll unsortedSum[100005],sortedSum[100005];
vector<int> A;
int main()
{
    unsortedSum[0] = 0;
    sortedSum[0] = 0;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        A.push_back(x);
        unsortedSum[i] = unsortedSum[i-1]+x;

    }
    sort(A.begin(),A.end());
    for(int i=0;i<n;++i)
    {
        sortedSum[i+1] = sortedSum[i]+A[i];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if(t == 1)
            cout<<unsortedSum[r]-unsortedSum[l-1]<<endl;
        else
            cout<<sortedSum[r]-sortedSum[l-1]<<endl;


    }

}
