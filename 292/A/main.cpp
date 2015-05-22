#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int a,b,s;
   cin>>a>>b>>s;
   int dif = s - abs(a)-abs(b);
   if(dif < 0  || dif%2)
    cout<<"No";
   else
    cout<<"Yes";
}
