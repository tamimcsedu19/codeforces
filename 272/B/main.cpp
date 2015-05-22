#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;

int pointToReach;
string s1,s2;
int hit,miss;

void bt(int i,int pointOn)
{
    if(i==s2.size())
    {
        if(pointOn == pointToReach)
            ++hit;
        else
            ++miss;
        return;
    }
    if(s2[i]=='+')
        bt(i+1,pointOn+1);
    else if(s2[i] == '-')
        bt(i+1,pointOn-1);
    else
    {
        bt(i+1,pointOn+1);
        bt(i+1,pointOn-1);
    }

    return;


}

int main()
{
   hit=0;
   miss=0;
   pointToReach = 0;
   cin>>s1>>s2;
   for(int i=0;i<s1.size();++i)
    {
        if(s1[i]=='+')
            pointToReach++;
        else
            pointToReach--;

    }
    bt(0,0);
    miss+=hit;
   long double p=(long double)((long double)hit/(long double)miss);
    cout<<fixed<<setprecision(10)<<p<<"\n";
}
