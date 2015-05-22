#include <iostream>

using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    bool flag = 1;
    for(int i=s.size()-1;i>=0;--i)
    {
        if(flag == 1)
        {
            if(s[i] == 'z')
                s[i] = 'a';
            else
            {
                s[i]++;
                flag = false;
            }
        }
    }
    if(s == t)
        cout<<"No such string\n";
    else
        cout<<s;


}
