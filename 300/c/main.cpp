#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> days;
vector<int> h;
int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int d,hi;
        cin>>d>>hi;
        days.push_back(d);
        h.push_back(hi);
    }
    int maxh = h[0]+days[0]-1;
    for(int i=0;i<(m-1);++i)
    {
        int diff = days[i+1]-days[i];
        int hdiff = abs(h[i]-h[i+1]);
        int bdiff = diff - hdiff;
        if(bdiff<0)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        maxh = max(max(h[i],h[i+1])+(bdiff/2),maxh);



    }
    maxh = max(h[m-1]+n-days[m-1],maxh);
    cout<<maxh;

}
