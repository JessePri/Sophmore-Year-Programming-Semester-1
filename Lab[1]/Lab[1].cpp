#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
using namespace std;


/* Overall flow of the program:
Get some input for the title
Get some input for column header #1
Get some input for column header #2

Until the user types "-1":
Get input for a string
Validate input
If valid...
   Split
   Validate second half of input
   If also valid...
      Store separate pieces

Print out data in table format

Print out data in chart format
*/
string dataTitle;
string column1;
string column2;
vector<string> data1;
vector<int> data2;

void SetTitle() {
    cout << "Enter a title for the data:" << endl;
    getline(cin, dataTitle);
    cout << "You entered: " << dataTitle << endl;
}

void SetHeaders() {
    cout << "Enter the column 1 header:" << endl;
    getline(cin, column1);
    cout << "You entered: " << column1 << "\n";

    cout << "Enter the column 2 header:" << endl;
    getline(cin, column2);
    cout << "You entered: " << column2 << "\n";
}

void SetDataPoints() {
    string input;
    bool breakpoint;
    do {
        breakpoint = false;
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, input);
        string::const_iterator end = input.cend();
        int commaCount = 0;
        string data1Member = "";
        string data2Temp = "";
        int data2Member = 0;
        for (auto iter = input.cbegin(); iter != end; ++iter) {
            if (*iter == ',') {
                ++commaCount;
                if (commaCount > 1) {
                    cout << "Error: Too many commas in input." << endl;
                    breakpoint = true;
                    break;
                }
            } else if (commaCount == 0) {
                data1Member += *iter;
            } else if (commaCount == 1) {
                data2Temp += *iter;
            }
        }
        if (commaCount == 0 && data1Member == "-1") {
            cout << endl;
            break;
        } else if (commaCount == 0) {
            cout << "Error: No comma in string." << endl;
        } else {
            try {
                data2Member = stoi(data2Temp);
                data2.push_back(data2Member); 
                data1.push_back(data1Member);
                cout << "Data string: " << data1Member << endl;
                cout << "Data integer: " << data2Member << endl;
            } catch (exception e) {
                if (breakpoint) {
                    continue;
                }
                cout << "Error: Comma not followed by an integer." << endl;
            }
        }
    } while(input != "-1");

}
void PrintTable() {
    cout << right << setw(33) << dataTitle << endl;
    cout << left << setw(20) << column1;
    cout << "|" << setw(23);
    cout << right << column2 << endl;
    int size = data1.size();
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << left << setw(20) << data1[i];
        cout << "|" << setw(23);
        cout << right << data2[i] << endl;
        int size = data1.size(); 
    }
    cout << endl;
}

void PrintStar(int i) {
    for (int j = 0; j < data2[i]; ++j) {
        cout << "*";
    }
}
void PrintHistogram() {
    int size = data1.size();
    for (int i = 0; i < size; ++i) {
        cout << right << setw(20) << data1[i] << " ";
        PrintStar(i);
        cout << endl;
    }
}

int main() {
    SetTitle();
    SetHeaders();
    SetDataPoints();
    PrintTable();
    PrintHistogram();
    return 0;
}