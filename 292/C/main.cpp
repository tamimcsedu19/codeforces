#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f[12];
int main()
{
    memset(f,0,sizeof f);
    int x; cin>>x;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); ++i)
        ++f[s[i]-'0'];


        while(f[9]!=0)
        {
            f[3]+=2;
            f[2]+=2;
            f[7]+=1;
            f[9]--;

        }
        while(f[8]!=0)
        {
            f[2] += 3;
            f[7] += 1;
            f[8]--;

        }

        while(f[6]!=0)
        {
            f[3]++;
            f[5]++;
            --f[6];
        }

        while(f[4]!=0)
        {
            f[2]+=2;
            f[3]++;
            f[4] -- ;

        }


    string res = "";
    for(int i=2;i<=9;++i)
    {
        for(int j = 0;j<f[i];++j)
            res += i+'0';

    }
    sort(res.begin(),res.end());
    reverse(res.begin(),res.end());
    cout<<res<<"\n";




}
