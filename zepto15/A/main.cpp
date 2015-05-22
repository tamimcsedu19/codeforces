#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    bool ans = false;
    for(int i=0;i<s.size();++i)
    {
        if(s[i] == '.')
            continue;
        for(int j=i+1;j<s.size();++j)
        {
            if(s[j] == '.')
                continue;
            bool possible = true;
            int diff = j-i;
            int curr = i;
            for(int k=0;k<4;++k)
            {
                curr = curr+diff;
                if(curr >= s.size() || s[curr] == '.')
                    possible = false;

            }
            if(possible)
                ans = true;




        }




    }
    if(ans)
        cout<<"yes";
    else
        cout<<"no";
}
