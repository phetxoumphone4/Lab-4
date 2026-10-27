/* 
Linden Phetxoumphone
Computer Science Fall 2026
October 23, 2026
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// There must be temperatures in the file "temps.txt" for this program to work correctly.

int main()
{
    int num_stars;
    int number; 
    ifstream inputFile("temps.dat");
// Check if the file was opened successfully
    
	// Display the header for the table
    for (int i = -30; i <= 120; i += 10) {
        cout << setw(10) << i;
    }
    
	cout << endl;

	// Read numbers from the file and display them with stars
    while (inputFile >> number) {
    
		num_stars = round(number / 3.0);

		// Check if the number is within the valid range
        if (number >= -30 && number <= 120) {

			// Display the number and stars based on its value
            if (number < 0) {

				// Display the number and stars for negative values
                cout << to_string(number);
				int stars = abs(num_stars);
                
				// Calculate the width for alignment and display stars
				cout << setw(39 - (stars * 3) - to_string(number).length()) << "";

                for (int i = 0; i < stars; i++) {
                    cout << setw(3) << "*";
                }
				// Display the vertical bar after the stars
				cout << "|";

            }
			// Display the number and stars for positive values
			else if (number > 0) {
				cout << to_string(number);
				cout << setw(40 - to_string(number).length()) << "|";
                
				for (int i = 0; i < num_stars; i++) {
					cout << setw(3) << "*";

				}
            }
			// Display the number and vertical bar for zero
            else {

                cout << to_string(number);
				cout << setw(40 - to_string(number).length()) << "|";

            }
			cout << endl;
        }
    }

    inputFile.close();

}
