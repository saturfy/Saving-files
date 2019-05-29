/*
This prog  Program creates a struct data type vector can fill it with data and save that data to disk tha read data from disk.
*/
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // formatting output

using namespace std;
const unsigned int N = 10; // length of the record vector 
const unsigned int l = 10; // lenght of the name 

struct record {
	char name[l]="EMPTY"; // Name is a 10 lenght char array 
	int score = 0; // score is and int number given to player
};

// this function prints the results from the array which size is fixed
void printr(record(&list)[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << right << setfill(' ') << setw(2) << i + 1 << ' ' << left << setfill('.') << setw(15) << list[i].name << list[i].score << "\n";
	}
}

// this function lets the user to fill data into the array of given length
void readusr(record(&list)[N])
{
	while (true) {
		unsigned int n; // the player number we edit
		cout << "player number ? max: " << N << ", to quit type in 0." << "\n";
		cin >> n; // Player number : 1-10
		if (n == 0) { break; }
		else {
			cout << "palyer name ? max 10 characters" << "\n";
			cin.ignore(256, '\n');  // the enter from the cout is still in the stream so we ignore it and cin work properly
			cin.getline(list[n - 1].name, l + 1); // reading l characters into name, until we reach a \n. 
			cout << "player score? " << "\n";
			cin >> list[n - 1].score;
			printr(list);
		}
	}
}

void savelist(record (&list)[N])
{
	// we open a file for saving the data
	ofstream out ("data.txt");
	if (out.is_open()) // checking the file
	{
		// writing the elements of on struct object from the list into one line so we will have N number of lines
		for (int i = 0; i < N; i++)
		{
			out << list[i].name << ' ' << list[i].score << "\n";
		}
		cout << "Saving is succesful" << "\n";
		out.close();
	}
	else cout << "cannot open file" << "\n";
}


int main()
{
	record playerlist[N];
	record (&list)[N] = playerlist; // reference for the list

	// Read data from console into the array of struct
	readusr(list);

	// Save data into the file
	savelist(list);

	string s;
	getline(cin, s);



}