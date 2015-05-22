#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{

  ll n;
  cin>>n;
  ll a = 2;
  ll add = 5;
  ll cnt = 0;
  for(int i=0;i<=10000000;++i)
  {
    if(a > 1000000000005ll)
        break;
    ll d = (n-a);
    if(a > n)
        break;
    if(d%3 == 0)
        ++cnt;

    a+=add;
    add+=3;
  }
  cout<<cnt<<"\n";


}
