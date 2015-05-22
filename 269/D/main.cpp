#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> compute_z(const vector<int> &S)
{

    vector<int> Z(S.size(),0);
    int l=0,r=0;
    for(int i=1;i<S.size();++i)
    {
        if(i>r)
        {
            l=r=i;
            while(r<S.size() && S[r] == S[r-l])++r;
            Z[i] = r-l; --r;
        }
        else
        {
            int k = (i-l);
            if(Z[k] < (r-i+1))
                Z[i] = Z[k];
            else
            {
                l=i;
                while(r<S.size() && S[r] == S[r-l]) ++r;
                Z[i] = r-l; --r;

            }
        }



    }
    return Z;







}



int main()
{
  int n,w;
  cin>>n>>w;
  if(w == 1)
  {
    cout<<n<<"\n";
    return 0;
  }
  vector<int> N,W;
  int prev;
  cin>>prev;
  for(int i=1;i<n;++i)
  {
    int x;
    cin>>x;
    N.push_back(x-prev);
    prev = x;

  }
  cin>>prev;
  for(int i=1;i<w;++i)
  {
    int x;
    cin>>x;
    W.push_back(x-prev);
    prev = x;

  }
  vector<int> S;
  for(int i=0;i<W.size();++i)
  {
    int x=W[i];
    S.push_back(W[i]);

  }
  S.push_back(1000000003);
  for(int i=0;i<N.size();++i)
  {
    int x=N[i];
    S.push_back(N[i]);
  }
  vector<int> Z=compute_z(S);

  int cnt = 0;
  for(int i=W.size();i<Z.size();++i)
    if(Z[i] == W.size())
        ++cnt;
  cout<<cnt;



}
