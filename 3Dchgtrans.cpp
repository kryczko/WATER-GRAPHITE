/*This code intends to go through a LOCPOT file produced by vasp and plot the electrostatic potential as a function of z*/


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std;

double max(double array[], int length)
{
	double start = array[0];
	for (int i = 1; i < length; i ++)
	{
		if (array[i] > start)
		{
			start = array[i];
		}
	}
return start;
}


int main()
{

string infile0, infile1, infile2;
ifstream inputfile0, inputfile1, inputfile2;
ofstream outputfile;

double zlattice, ylattice;
int  num;
cout << "Please enter the graphite inputfile: ";
cin >> infile0;
cout << "Please enter the water inputfile: ";
cin >> infile1;
cout << "Please enter the graphite-water inputfile: ";
cin >> infile2;
cout << "\n##### CODE RUNNING, PLEASE WAIT A MOMENT #####\n\n";


inputfile0.open(infile0.c_str());
inputfile1.open(infile1.c_str());
inputfile2.open(infile2.c_str());
outputfile.open("esp_yz_contour.dat");


vector <string> stuff0;
string words0;
vector <double> good0;
double values0;
int count0 = 0, noa0, realstart0(100000);
while(!inputfile0.eof())
{
	inputfile0 >> words0;
	stuff0.push_back(words0);
		
	if (count0 == 11)
	{
		noa0 = atoi (words0.c_str());
		realstart0 = count0 + noa0*3 + 2; // for no selective dynamics
		
	}

	if (count0 >= realstart0)
	{
		values0 = atof ( words0.c_str() );	
		good0.push_back(values0);
		//cout << "The data file should start here!\n";

	}
	count0 ++;
}


int nx0 = good0[0], ny0 = good0[1], nz0 = good0[2];
good0.erase(good0.begin());
good0.erase(good0.begin());
good0.erase(good0.begin());


// for water part

vector <string> stuff1;
string words1;
vector <double> good1;
double values1;
int count1 = 0, noa1, noa2, noa3, realstart1(100000);
while(!inputfile1.eof())
{
        inputfile1 >> words1;
        stuff1.push_back(words1);
	
        if (count1 == 11)
        {
                noa1 = atoi (words1.c_str());
                           
        }
	if (count1 == 12)
	{
		noa2 = atoi (words1.c_str());
		noa3 = noa1 + noa2;
		realstart1 = count1 + noa3*3 + 2;
	}
        if (count1 >= realstart1)
        {
                values1 = atof ( words1.c_str() );
                good1.push_back(values1);
                //cout << "The data file should start here!\n";
    
        }
        count1 ++;
}   
    
int nx1 = good1[0], ny1 = good1[1], nz1 = good1[2];
 
good1.erase(good1.begin());
good1.erase(good1.begin());
good1.erase(good1.begin());


//for the water-graphite part
vector <string> stuff2;
string words2;
vector <double> good2;
double values2;
int count2 = 0, noa4, noa5, noa6, noa7, realstart2(100000);
while(!inputfile2.eof())
{
        inputfile2 >> words2;
        stuff2.push_back(words2);
	
        if (count2 == 11)
        {
                noa4 = atoi (words2.c_str());
                                
        }
	if (count2 == 12)
	{
		noa5 = atoi (words2.c_str());
	}
	if (count2 == 13)
	{
		noa6 = atoi (words2.c_str());
		noa7 = noa4 + noa5 + noa6;
		realstart2 = count2 + noa7*3 + 2;
	}
        if (count2 >= realstart2)
        {
                values2 = atof ( words2.c_str() );
                good2.push_back(values2);
                //cout << "The data file should start here!\n";
    
        }
        count2 ++;
}   
cout << "read input";    
int nx2 = good2[0], ny2 = good2[1], nz2 = good2[2];
 
good2.erase(good2.begin());
good2.erase(good2.begin());
good2.erase(good2.begin());


//outputting the new values

for (int i = 0; i < good2.size(); i ++)
{
	if (i !=0 && i % 5 == 0)
	{
		outputfile << "\n";
	}
	outputfile << good2[i] - good1[i] - good0[i] << "  ";
}

cout << "The data has been placed in \"esp_yz_contour.dat\" and can now easily be plotted with gnuplot." << endl;



outputfile.close();
return 0;
}
