#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll C,Hr,Hb,Wr,Wb,maxres;


int main()
{

    cin>>C>>Hr>>Hb>>Wr>>Wb;
    ll nb = (C/Wb);
    ll nr = (C/Wr);
    cout<<max(Hr*nr,Hb*nb);



}
