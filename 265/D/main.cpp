#include <iostream>

using namespace std;
typedef long long int ll;
int digits[24];
long long int res[24];







void next()
{


}
int cnt;
void first(int mask,int taken)
{
    if(taken == 6)
    {
        int p1,p2,p3;

        return;
    }
    for(int i=0;i<24;++i)
    {
        if (!((1<<i)&mask))
            first(mask|(1<<i),taken+1);

    }

}


int main()
{
    first(0,0);
    cout<<cnt;
}
