#include <iostream>
#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
bool prime[1000005];

void SieveOfEratosthenes()
{
    for(int i=2;i<maxn;++i)
        prime[i] = true;
    for(int i=2;i*i<maxn;++i)
    {
        if(prime[i])
        {
            for(int j=i+i;j<maxn;j+=i)
                prime[j] = false;

        }

    }

}


int main()
{
    int x;
    cin>>x;
    int a,b;
    SieveOfEratosthenes();
    for(int i=2;i<(x-1);++i)
    {
        if((!prime[i]) && (!prime[x-i]))
        {
            a=i;
            b=x-i;
            break;
        }
    }
    cout<<a<<" "<<b;

}
