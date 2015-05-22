#include <iostream>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int s = ((s1[0]-48)*10+(s1[1]-48))*60+(s1[3]-48)*10+s1[4]-48,t=((s2[0]-48)*10+(s2[1]-48))*60+(s2[3]-48)*10+s2[4]-48;
    int sleep = s-t;
    if(sleep<0)
        sleep+=1440;
    int hh = sleep/60;
    int mm = sleep%60;
    if(hh<10)
        cout<<0;
    cout<<hh<<':';
    if(mm<10)
        cout<<0;
    cout<<mm<<endl;
}
