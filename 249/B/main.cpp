#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
string s;

int main()
{
    int k;
    cin>>s>>k;
    for(int i=0;i<s.size();++i)
    {
        int range = min((int)(s.size()-1),i+k);

        int j = i,maxv = s[i];
        for(int h=i;h<=range;++h)
        {
            if(s[h]>maxv)
            {
                maxv = s[h];
                j = h;
            }

        }
        for(;j>i;--j)
        {
            if(s[j-1]<s[j])
            {
                swap(s[j-1],s[j]);
                k--;
            }
        }


    }
    cout<<s<<endl;


}
