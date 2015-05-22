#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
using namespace std;

vector<pair<int,int> > A;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        int x; cin>>x;
        A.push_back({x,i});

    }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
    }
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();++i)
    {
        if(i%2) A[i].first = 0;
        else A[i].first = 1;
        swap(A[i].first,A[i].second);
    }
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();++i)
        cout<<A[i].second<<" ";


}
