#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int i = 0;
    while(i<s.size() && s[i] == '9')
        ++i;
    for(;i<s.size();++i)
    {
        int d = s[i]-'0';
        if(9-d < d)
            s[i] = 9-d + '0';

    }
    s.erase(0, s.find_first_not_of('0'));
    if(s == "")
        cout<<0<<endl;
    else
        cout<<s<<endl;

}
