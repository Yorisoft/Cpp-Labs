// The goal of this lab is to help you get familiar with C++ structs.It is also an opportunity to practice writing
// and debugging a program with multiple functions.Be sure that you read this entire document before you being
// coding
//
// Prof. Peter Morgan
// CSC237 Lab09: Pointers
// Yelsin Sepulveda
// November 20, 2020.

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

struct MovieData {
	string title, director;
	int yearRealeased;
	double runningTime;
};
//void displayMovie(MovieData *ptr);
void populateMovieDataArray(MovieData* arrayPtr, int arraySize);
void displayMovieDataArray(MovieData* arrayPtr, int arraySize);
MovieData* findLongestMovie(MovieData* arrayPtr, int arraySize);

int main() {
	MovieData Lmovies, *moviesPtr;
	int nMovies;
	
	while (true) {
		cout << "Enter desired array size: ";
		cin >> nMovies; cin.ignore(100, '\n');

		moviesPtr = new MovieData[nMovies];
		cout << "moviesPtr = " << moviesPtr << endl;

		populateMovieDataArray(moviesPtr, nMovies);
		displayMovieDataArray(moviesPtr, nMovies);

		cout << "Longest Movie is list:" << endl;
		Lmovies = *findLongestMovie(moviesPtr, nMovies);
		cout << "\t\t" << setw(10) << right << "Title       : " << Lmovies.title << endl;
		cout << "\t\t" << setw(10) << right << "Ditector    : " << Lmovies.director << endl;
		cout << "\t\t" << setw(10) << right << "Released    : " << Lmovies.yearRealeased << endl;
		cout << "\t\t" << setw(10) << right << "Running Time: " << Lmovies.runningTime << endl;

		cout << "Longest Movie in list: " << Lmovies.title  << endl;

		cout << "Longest Movie is: " << Lmovies.runningTime << "  minutes long" << endl;

		cout << "DELETING array " << moviesPtr <<endl;
		delete[] moviesPtr;
		system("pause");
	}

	return 0;
}

void populateMovieDataArray(MovieData *arrayPtr, int arraySize) {
	for (int y = 0; y < arraySize; y++) {
		cout << "Enter Title " << y << ": ";
		getline(cin, (arrayPtr + y)->title);

		cout << "Enter Director " << y << ": ";
		getline(cin, (arrayPtr + y)->director);

		cout << "Enter Year Released " << y << ": ";
		cin >> (arrayPtr + y)->yearRealeased; cin.ignore(100, '\n');

		cout << "Enter running time (minutes) " << y << ": ";
		cin >> (arrayPtr + y)->runningTime; cin.ignore(100, '\n');
	}
}

void displayMovieDataArray(MovieData *arrayPtr, int arraySize) {
	for (int y = 0; y < arraySize; y++) {
		cout << (arrayPtr + y) << ": moviesPtr[" << y << "] =" << endl;
		cout << "\t\t" << setw(10) << right << "Title       : " << (arrayPtr + y)->title << endl;
		cout << "\t\t" << setw(10) << right << "Ditector    : " << (arrayPtr + y)->director << endl;
		cout << "\t\t" << setw(10) << right << "Released    : " << (arrayPtr + y)->yearRealeased << endl;
		cout << "\t\t" << setw(10) << right << "Running Time: " << (arrayPtr + y)->runningTime << endl;
	}
}

MovieData* findLongestMovie(MovieData *arrayPtr, int arraySize) {
	MovieData *longestMoviePtr = arrayPtr;	// starting point is first movie struct

	for (int y = 1; y < arraySize; y++) {
		(arrayPtr + y)->runningTime > longestMoviePtr->runningTime ? longestMoviePtr = arrayPtr + y : longestMoviePtr;
	}

	return longestMoviePtr;
}