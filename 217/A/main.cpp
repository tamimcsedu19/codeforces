#include <iostream>

using namespace std;

int main()
{
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    if(r1 == r2 ||  c1 == c2)
        cout<<1<<" ";
    else
        cout<<2<<" ";

    int cor1 = r1+c1,cor2 = r2+c2;
    if((cor1%2 == 0 && cor2 %2!=0) || (cor2%2 == 0 && cor1 %2!= 0))
        cout<<0<<" ";
    else if(abs(r1-r2) == abs(c1-c2))
        cout<<1<<" ";
    else
        cout<<2<<" ";


    int dis1 = abs(r1-r2),dis2 = abs(c1-c2);
    if(dis1<dis2)
        cout<<dis1+(dis2-dis1)<<endl;
    else if(dis1>dis2)
        cout<<dis2+abs(dis2-dis1)<<endl;
    else
        cout<<dis2<<endl;

}
