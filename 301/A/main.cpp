#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    string s1,s2; cin>>s1>>s2;
    int minv = 0;
    for(int i=0;i<s1.size();++i)
    {
        int d1 = s1[i],d2=s2[i];
        minv+=min(abs(d1-d2),min(d1+9-d2+1,d2+9-d1+1));


    }
    cout<<minv;
}
