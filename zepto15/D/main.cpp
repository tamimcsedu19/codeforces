#include <iostream>
#define maxn 1000006
using namespace std;
int lps[maxn];
string s;
void computeLPS()
{
    int len = 0;
    lps[0] = 0;
    int i=1;
    while(i<s.size())
    {
        if(s[i] == s[len])
            lps[i++] = ++len;
        else
        {
            if(len!=0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }

    }

}


int main()
{

    int n,k; cin>>n>>k;
    cin>>s;
    computeLPS();
    string res;
    for(int i=0;i<s.size();++i)
    {
        int lenS = i - lps[i]+1;
        int repeated = (i+1)/lenS;
        if(repeated <k)
        {
            cout<<0;
            continue;
        }
        int lenA = (repeated % k) * lenS + (i+1)%lenS;
        if(lenA<=(lenS*(repeated/k)))
            cout<<1;
        else
            cout<<0;

    }


}
