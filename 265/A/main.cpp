#include <iostream>
#include <bits/stdc++.h>

using namespace std;
char A[105];
char add[105];
int main()
{
    int n;
    cin>>n;
    int carry = 1;
    for(int i=0;i<n;++i)
    {
        cin>>A[i];
        add[i] = (carry^A[i]);
        carry = (carry&A[i]);
    }
    int cnt = 0;
    for(int i=0;i<n;++i)
        if(A[i]!=add[i])
            ++cnt;
    cout<<cnt<<endl;

}
