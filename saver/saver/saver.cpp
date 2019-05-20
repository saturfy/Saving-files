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



int main()
{
	record playerlist[N];

	// Read data from console into the array of struct
	while(true) {
		unsigned int n; // the player number we edit
		cout << "player number ? max: " << N << ", to quit type in 0." << "\n";
		cin >> n; // Player number : 1-10
		if (n == 0) { break; }
		else {
			cout << "palyer name ? max 10 characters" << "\n";
			cin.ignore(256, '\n');  // the enter from the cout is still in the stream so we ignore it and cin work properly
			cin.getline(playerlist[n-1].name, l + 1); // reading l characters into name, until we reach a \n. 
			cout << "player score? " << "\n";
			cin >> playerlist[n-1].score;

			for (int i = 0; i < N; i++)
			{
				cout<< right<< setfill(' ') << setw(2) << i + 1 << ' ' << left << setfill('.') << setw(15) << playerlist[i].name << playerlist[i].score << "\n";
			}
		}
	}

	string s;
	getline(cin, s);



}