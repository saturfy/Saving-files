
#include "pch.h"
#include <iostream>
#include <fstream>  // for file operations 
#include <string>
#include <vector>
#include <iomanip>  // formatting

// this code saves a fixed sized array  of struct objects, THis is not the best solution because the data type is seriallzed into the file. If the strucure changes
// because compiler optimization than the file becomes unreadable. 

using namespace std;

const unsigned int  VS = 10; // the size of the vector
struct record  // we store players restuls in a list like this
{
	string name = "EMPTY";
	int score = 0;

};

int main()
{
	record  playerlist[VS];  // the data array
	record player;  // this is where we soter one element temporarily
	int pn=1; // player number
	
	
	while (1) {
		cout << "Which player's data? (1 -10) If you want to quit type 0. " << "\n";
		cin >> pn;
		if (pn < 0 || pn > 10) {
			cout << "Wrong number, max number of palyers is 10. " << "\n";
		}
		if (pn == 0) break;
		// read data into the palyer number

		cout << "player name" << "\n";
		cin >> playerlist[pn-1].name;
		cout << "player score" << "\n";
		cin >> playerlist[pn-1].score;
	}
	

	int size =VS * sizeof(record);  // this is the size of the data we want to save

	
	// SAVING DATA TO FILE
	ofstream out("log.txt", ios::out | ios::binary);  // create object which will handle saving into log.txt

	if (out.is_open()) // cheking file open status
	{
		out.write(reinterpret_cast<const char*>(&playerlist), size);  // the reinterpret correctly casts the player list pointer into a char pointer, which can be written out
	}
	else
		cout << "Cannot open file" << "\n";

	out.close(); // close file after use

	// READING DATA FROM FILE

	ifstream in("log.txt", ios::in | ios::binary);  // open input file

	//record* inputrec;  // record type pointer 
	//inputrec =  new record[VS]; // allocate memory for the file , THIS IS AN ADDRESS

	record inputrec[VS];

	if (in.is_open()) // check file open
	{
		in.read(reinterpret_cast<char *>(&inputrec), size);
	}
	else
		cout << "cannot open file" << "\n";

	in.close();  // close file 

	// show the results we loaded in earlier

	cout << "your result is  " << "\n";

	for (int i = 0; i < VS; i++)
	{
		
		cout<< setw(2) <<  i+1 << " " << left << setfill('-') << setw(10)  <<  inputrec[i].name <<  inputrec[i].score << setfill(' ')<< right<<"\n";
	}
	
	// delete does not work because reinterpret cast

	// delete[] inputrec
	

	// wait for enter at the end
	cout << "to end proram, type enter" << "\n";
	string s;
	getline(cin, s);
	
	return 0;
}


