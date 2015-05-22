#include <iostream>

using namespace std;
typedef long long int ll;
ll A[500005];
ll cum[500005];
int main()
{
    cum[0] = 0;
    ll n;
    cin>>n;
    for(ll i=1;i<=n;++i)
    {

        cin>>A[i];
        cum[i] = cum[i-1]+A[i];
    }
    ll sumi=0,sumj=0;
    ll cnt = 0;
    ll i,j;
    for(i=1,j=n;i<(j-1);++i)
    {
        int icnt = 0;
        sumi+=A[i];
        while(sumi == (sumi+A[i])){

          ++icnt
          ++i;

        }

        while(j>(i+1) && (sumj+A[j]<sumi))
        {
            sumj+=A[j];
            --j;
        }
        int jcnt = 0;
        while((sumj+A[j] == sumi) &&(cum[j-1]-cum[i]) == sumi)
        {
            jcnt++;

        }






    }
    cout<<cnt;




}
