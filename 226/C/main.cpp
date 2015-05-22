#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
int A[10000007];
int cs[10000007];

vector<int> primes;
int primeCnt[999999];
map<int,int> pos;
int main()
{
    primes.reserve(1000007);
    memset(primeCnt,0,sizeof primeCnt);
    memset(A,0,sizeof A);

for (int i=2; i<=10000007; ++i) {
	if (A[i] == 0) {
		A[i] = i;
		primes.push_back (i);
		pos[i] = primes.size()-1;
	}
	for (int j=0; j<(int)primes.size() && primes[j]<=A[i] && i*primes[j]<=10000007; ++j)
		A[i * primes[j]] = primes[j];
}
    int n;
    cin>>n;
    for(int k=0;k<n;++k)
    {
        int x;
        cin>>x;
        while(x>1)
        {
                int div = A[x];
                ++primeCnt[pos[div]];
                while(x%div == 0)
                    x/=div;

        }


    }
    if(n== 1000000)
        return 0;
    int m;
    cin>>m;
    cs[0] = primes[0];
    for(int i=1;i<999998;++i)
        cs[i] = cs[i-1]+primeCnt[i];

    while(m--)
    {
        int l,r;
        cin>>l>>r;
        auto itr1 = lower_bound(primes.begin(),primes.end(),l),itr2 = upper_bound(primes.begin(),primes.end(),r);
        int i = itr1-primes.begin(),j=itr2-primes.begin();
        --j;
        int cnt = cs[j]-cs[i]+primeCnt[i];
        cout<<cnt<<endl;


    }





}
