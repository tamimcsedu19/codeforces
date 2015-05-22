#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
vector<int> B;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        B.push_back(x);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int i=0,j=0;
    while(i<A.size()&&j<B.size())
    {
        if(A[i]<=B[j])
        {
            ++i;
            ++j;
        }
        else
            ++j;

    }
    cout<<A.size()-i<<endl;


}
