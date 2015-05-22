#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
typedef long long int ll;
using namespace std;
vector<ll> A;
map<int,int> mp;
set<int> res;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        A.push_back(x);

    }
    sort(A.begin(),A.end());
    for(int i=1;i<n;++i)
        ++mp[A[i]-A[i-1]];
    if(mp.size()>2)
    {
        cout<<0<<endl;
        return 0;
    }
    else if(mp.size() == 0)
    {
        cout<<-1<<endl;
        return 0;
    }
    else if(mp.size() == 1)
    {


        map<int,int>::iterator itr = mp.begin();
        if(itr->second == 1)
        {
            if(itr->first % 2 == 0 && itr->first != 0)
                res.insert(A[0]+(itr->first /2));
        }
        res.insert(A[0]-itr->first);
        res.insert(A[A.size()-1]+itr->first);

    }
    else{
    map<int,int>::iterator itrl = mp.begin(),itrr = ++itrl;
    --itrl;
    if(itrl->second == 1 && (itrr->first*2) ==  itrl->first)
    {
        int i;
        for(i=0;i<(n-1);++i)
            if(A[i+1]-A[i] == itrl->first)
                break;
        if((A[i+1]-A[i])%2 == 0)
            res.insert(A[i]+(A[i+1]-A[i])/2);
    }
    if(itrr->second == 1 && (itrl->first*2) ==  itrr->first)
    {
        int i;
        for(i=0;i<(n-1);++i)
            if(A[i+1]-A[i] == itrr->first)
                break;
        if((A[i+1]-A[i])%2 == 0)
            res.insert(A[i]+(A[i+1]-A[i])/2);
    }


    }
    cout<<res.size()<<endl;
    for(set<int>::iterator i=res.begin();i!=res.end();++i)
        cout<<*i<<" ";



}
