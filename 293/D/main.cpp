#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double lgFactors[2005];
double factorial[2005];
double C(int n,int k)
{
    return 1.0*(lgFactors[n]-(lgFactors[k]+lgFactors[n-k]));

}
int main()
{

    factorial[0] = 1;
    factorial[1]=1;
    lgFactors[1] = 0;
    for(int i=2;i<=2004;++i)
    {
        factorial[i] = factorial[i-1]*i;
        lgFactors[i] = lgFactors[i-1] + log2(i);

    }


    int n,t;
    double p;
    cin>>n>>p>>t;
    double E = 0.0;
    for(int ppl = 1;ppl<=min(n,t);++ppl)
    {
        for(int lastSec = ppl;lastSec<=t;++lastSec)
        {
            double ncr = C(lastSec-1 , ppl-1);
            double powppl = 0.0;
            if((p) < 1e-9)
                if(ppl!=0)
                    continue;
            if(p > 1e-9)
                powppl = 1.0*ppl*log2(p);
            double pownoten = 0.0;
            if((1-p) < 1e-9)
                if(lastSec-ppl!=0)
                    continue;
            if((1-p) > 1e-9)
                pownoten = 1.0*(lastSec-ppl)*log2(1-p);

            E +=  pow(2,ncr+powppl+pownoten);


        }

    }
    cout<<fixed<<setw(8)<<E;


}
