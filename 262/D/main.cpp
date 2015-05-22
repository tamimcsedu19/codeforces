#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<ull> U,M,L;
int main()
{
    U.push_back(3);
    M.push_back(2);
    L.push_back(1);
    for(int i=0;i<40;++i)
    {
        U.push_back((U.back()<<1));
        M.push_back(U.back()-1);
        L.push_back((L.back()<<1)|1ll);

    }
    ull l,r,k;
    cin>>l>>r>>k;
    if(k>=4)
    {
        for(ull cnt = 0,i=3;cnt<10 && (l+i)<=r;++i,++cnt)
        {
            ull x1 = l+i,x2=x1-1,x3=x2-1,x4=x3-1;
            if(!(x1^x2^x3^x4))
            {
                cout<<0<<"\n"<<4<<"\n";
                cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4;
                return 0;
            }

        }
    }
    if(k>=3)
    {
        for(int i=0;i<U.size();++i)
        {
            if(U[i]<=r && L[i]>=l)
            {
                cout<<0<<"\n"<<3<<"\n";
                cout<<U[i]<<" "<<M[i]<<" "<<L[i];
                return 0;


            }


        }
    }
    if(k>=2)
    {
            ull res1,res2;
            ull least = 0xFFFFFFFFFFF;
            for(ull cnt = 0,i=1;cnt<10 && (l+i)<=r;++i,++cnt)
            {
                ull x1 = l+i,x2=x1-1;
                if((x1^x2) < least)
                {
                    res1 = x1;
                    res2 = x2;
                    least = x1^x2;
                }


            }
            if(l<least)
            {
                cout<<l<<"\n"<<1<<"\n"<<l;
                return 0;
            }
            else
            {
                cout<<least<<"\n"<<2<<"\n"<<res1<<" "<<res2;
                return 0;
            }

    }
    cout<<l<<"\n"<<1<<"\n"<<l;






}
