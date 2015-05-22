#include <iostream>
#include <map>
using namespace std;

map<int,int> cmltv;
int A[400005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>A[i];
    }
    unsigned long long res = 0;
    int l=0,r=0;
    for(;r<n;++r)
    {
        int cnt = ++cmltv[A[r]];
        if(cnt==k)
        {
            while(l<=r){
                res+=(n-r);
                --cmltv[A[l]];
                if(A[l] == A[r] && cmltv[A[l]] < k )
                   {
                        ++l;
                        break;
                   }
                ++l;

            }
        }
    }
  cout<<res<<endl;



}
