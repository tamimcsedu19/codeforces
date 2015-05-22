#include <iostream>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int b1,b2,p1,p2;
        cin>>b1>>b2>>p1>>p2;
        bool miss = false;
        if(b1+b2<=p1+p2)
            miss = true;

        cin>>b1>>b2>>p1>>p2;
        if(b1+b2<=p1+p2)
            miss = true;
        if(miss)
            cout<<"Miss\n";
        else
            cout<<"Banglawash\n";

    }
}
