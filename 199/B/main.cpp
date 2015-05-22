#include <iostream>

using namespace std;
class test{

int a;
void t(){cout<<a<<endl;}
};
#define pi 3.14159265358979
int main()
{
	double r,h;
	cin>>r>>h;
	double v1 = pi*(r/2)*h*(r/2),v2 = ((pi*r*r)/2)*r;
	double v = v1+v2;
	double vb = (4.0/3.0)*(pi*(r/2)*(r/2)*(r/2));
	int x = v/vb;
	
	cout<<v1<<" "<<v2<<" "<<v<<" "<<vb<<endl;
	cout<<x/2<<endl; 
	
	
}
