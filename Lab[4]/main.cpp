#include <iomanip>
#include <iostream>
#include <vector>
// #include "LegoSetList.h"
using std::vector;
using std::string;
#include "extrafile.h"
using namespace std;


/* Mistakes made on this lab:
    -you forgot that a vector uses dynamic memory (why you made a dynamic vector pointer)
    -you then made a pointer to your object dynamic....
        -this will make things uglier (and slower)
*/

int main()
{
    cout << std::fixed << setprecision(2);
    cout << "Which file(s) to open?\n";
    cout << "1. lego1.csv" << endl;
    cout << "2. lego2.csv" << endl;
    cout << "3. lego3.csv" << endl;
    cout << "4. All 3 files" << endl;
    int option;
    cin >> option;
    vector<string> files {"lego1.csv", "lego2.csv", "lego3.csv"};
    /*======= Load data from file(s) =======*/
    LegoSetList* legoSL;
    if (option > 0 && option < 4) {
        vector<string> input {files[option - 1]};
        legoSL = new LegoSetList(input);
    } else {
        legoSL = new LegoSetList(files);
    }

    cout << "1. Most Expensive set" << endl;
    cout << "2. Largest piece count" << endl;
    cout << "3. Search for set name containing..." << endl;
    cout << "4. Search themes..." << endl;
    cout << "5. Part count information" << endl;
    cout << "6. Price information" << endl;
    cout << "7. Minifigure information" << endl;
    cout << "8. If you bought one of everything..." << endl;
    cout << "0. Exit" << endl;

    int choice;
    cin >> choice;
    cin.get(); // Clear newline character for any later input

    /*======= Print out how many sets were loaded =======*/
    cout << "Total number of sets: " << legoSL->GetSetCount() << endl;
    cout << endl;
    /*======= Based on the choice, execute the appropriate task and show the results =======*/
    if (choice == 1) {
        legoSL->MostExpensive(false);
    } else if (choice == 2) {
        legoSL->LargestPieceCount(false);
    } else if (choice == 3) {
        string name;
        getline(cin, name);
        legoSL->NameSearch(name);
    } else if (choice == 4) {
        string theme;
        getline(cin, theme);
        legoSL->ThemeSearch(theme);
    } else if (choice == 5) {
        legoSL->PartCount();
    } else if (choice == 6) {
        legoSL->Price();
    } else if (choice == 7) {
        legoSL->Minifig();
    } else if (choice == 8) {
        legoSL->Total();
    } else if (choice == 0) {
        delete legoSL;
        return 0;
    }
    delete legoSL;
    return 0;
}