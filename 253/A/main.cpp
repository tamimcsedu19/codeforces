#include <fstream>		// for ifstream
#include <iostream>		// for cin, cout and cerr
#include <string>		// for the string datatype
#include <cstdlib>		// needed for the exit function
#include <sstream>		//
#include <math.h>		//
#include <stdio.h>		//
#include <time.h>		//		//		//
#include <stdlib.h>		//
#include <time.h>		////
#include <sys/stat.h>	//
#include <cstring>
#include <unistd.h>
using namespace std;	//

int RunMe()
{
cout << "|";
sleep (125);
cout << "\b";
cout << "/";
sleep (125);
cout << "\b";
cout << "-";
sleep (125);
cout << "\b";
cout << "\\";
sleep (125);
cout << "\b";
cout << "|";
sleep (125);
cout << "\b";
cout << "/";
sleep (125);
cout << "\b";
cout << "-";
sleep (125);
cout << "\b";
cout << "\\";
}

int RunMe2()
{
sleep (60000);
}


void TimeTest()
{
	time_t start,end;
	char szInput [256];
	double dif;
	time (&start); // Start clock
// call program to Test runtime speed below
//	RunMe(); // Run for 1 second, show spinning wheel
//	RunMe2(); // Run for 60 seconds, verify program reports correct time.
	system("filename.exe"); // Run command line program

	time (&end);	// Stop clock
	dif = difftime (end,start);
	printf ("Program finished in %.2lf seconds \n", dif );
}

int main ()
{
	TimeTest();
	return 0;
}
