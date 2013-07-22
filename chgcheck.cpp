/*This code goes through the output of the chgtrans code to check that charge is conserved */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


// this is the main function
int main()
{

// declare string for the inputfile name
string infile;

// ask for the name of the inputfile
cout << "Please enter the name of the datafile: ";
cin >> infile;

// open the inputfile
ifstream inputfile;
inputfile.open(infile.c_str());

//go through the inputfile; we know that there is 2 columns of data
vector <double> z, chg;
double column1, column2;

while ( !inputfile.eof())
{
	inputfile >> column1 >> column2;
	z.push_back(column1);
	chg.push_back(column2);
}

// for loop to go through our new vector and add the chg terms up to see if it equates to 0
double sum = 0;
for (int i = 0; i < chg.size(); i ++)
{
	sum += chg[i];
}

// print out the value 
cout << "The sum of the charge is " << sum << ". I hope your charge is conserved.\n\n";


// close files and terminate program
inputfile.close();
return 0;
}	


