#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int cnt = 1,j=s.size()-1,i=s.size()-1;
    while(i>=0)
    {
        while(s[i]=='0') --i;
        if(j-i < i-1){
            ++cnt;
            --i;
            j=i;
        }
        else if(j-i == i-1 && s[i]<=s[0]){
            ++cnt;
            --i;
            j=i;
        }
        else
            break;



    }
    cout<<cnt<<endl;

}
