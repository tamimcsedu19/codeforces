#include <iostream>
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int a,b,c;
int sumDigit(int x)
{
    int sum = 0;
    while(x)
    {
        sum+=(x%10);
        x/=10;
    }
    return sum;

}
long long int p(int x)
{
    long long res = 1;
    for(int i=1;i<=a;++i)
        res*=x;
    return res;
}
vector<int> res;
int main()
{

    cin>>a>>b>>c;
    for(int i=1;i<=81;++i)
    {
        long long int pow = p(i);
        long long int x = pow*b+c;
        if((pow*b+c)>=1 && (pow*b+c)<1000000000)
        {
            if(sumDigit(x) == i)
                res.push_back(pow*b+c);

        }

    }

    cout<<res.size()<<"\n";
    for(int i=0;i<res.size();++i)
        cout<<res[i]<<" ";

}
