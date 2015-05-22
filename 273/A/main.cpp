#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0;
    for(int i=0;i<5;++i)
    {
        int x;
        cin>>x;
        sum+=x;
    }

    int i;
    for(i=1;i<=100;++i)
    {
        if(5*i == sum)
        {
            cout<<i;
            return 0;
        }

    }
    cout<<-1;




}
