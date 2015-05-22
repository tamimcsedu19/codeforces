#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int A[3002];
int main()
{

    int n;
    cin>>n;

    for(int i=1;i<=n;++i)
        cin>>A[i];
    cout<<n-1<<"\n";
    for(int i=1;i<n;++i)
    {
        int minv=INT_MAX;
        int mini=i;
        for(int j=i;j<=n;++j)
        {
            if(A[j]<minv)
            {
                minv = A[j];
                mini = j;
            }
        }
        cout<<i-1<<" "<<mini-1<<"\n";
        swap(A[i],A[mini]);


    }


}
