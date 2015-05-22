#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class stdnt{
    public:
        long long indx;
        long long c;
        long long lvl;
    bool operator<(const stdnt &x) const
    {
        return this->c > x.c;
    }
};

bool comp(const stdnt &x,const stdnt &y)
{return x.lvl>y.lvl;}
class bug{
public:
    long long idx;
    long long lvl;
    bool operator<(const bug &x) const
    {return lvl>x.lvl;}
};
vector<bug> Bugs;
long long s,n,m;
vector<stdnt> stdntInfo;
long long res[100005],finres[100005];
bool canDo(long long t)
{
    long long pass = 0;
    priority_queue<stdnt> pq;
    long long bi = 0,sj = 0;
    while(bi < m)
    {
        while( sj < n && stdntInfo[sj].lvl >= Bugs[bi].lvl)
         {
           pq.push(stdntInfo[sj]);
           ++sj;

         }
        if(pq.empty())
            return false;
        pass+=pq.top().c;
        if(pass>s)
            return false;
        long long last = bi+t;
        for(;bi<last && bi < m;++bi)
            res[Bugs[bi].idx] = pq.top().indx;
        pq.pop();

    }
    //if(n == 1000 && m == 100000 && s == 900 && t == 175)
      //  cout<<pass<<endl;
    return bi == m;

}
int main()
{
    cin>>n>>m>>s;
    for(long long i=0;i<m;++i)
    {
        bug tmp;
        cin>>tmp.lvl;
        tmp.idx = i+1;
        Bugs.push_back(tmp);

    }
    for(long long i=0;i<n;++i)
    {
        stdnt tmp;
        cin>>tmp.lvl;
        tmp.indx = i+1;
        stdntInfo.push_back(tmp);
    }
    for(long long i=0;i<n;++i)
        cin>>stdntInfo[i].c;
    sort(Bugs.begin(),Bugs.end());
    sort(stdntInfo.begin(),stdntInfo.end(),comp);
    long long l = 1,r = m,mid;

    while(l < r)
    {
        mid = (l+r)/2;
        if(canDo(mid)){
            r = mid;
            for(long long i=1;i<=m;++i)
                finres[i] = res[i];
        }
        else
            l = mid+1;
    }
    if(!canDo(m))
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
            for(int i=1;i<=m;++i)
                cout<<finres[i]<<" ";
    }




}
