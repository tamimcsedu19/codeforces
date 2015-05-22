/**

        THIS CODE IS NOT AC CODE

**/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<int,int> st;
int main()
{
    for(int i=0;i<6;++i)
    {
        int x;
        cin>>x;
        st[x]++;
    }
    if(st.size() > 3)
        cout<<"Alien";
    else if(st.size() == 3)
        cout<<"Bear";
    else if(st.size() == 2)
        cout<<"Elephant";


}
