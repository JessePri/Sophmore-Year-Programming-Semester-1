// #include "LegoSetList.h"  
#include "extrafile.h"   // Future not this is because of the lab
#include <iostream>
#include <fstream>
#include <sstream>

using std::istringstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

typedef LegoSetList::LegoSet LegoSet;

// Constructor and helpers
LegoSetList::LegoSetList(vector<string> files) {
    list = new vector<LegoSet>;
    for (string file: files) {
        read(file);
    }
}

void LegoSetList::read(string file) {
    string content;
    ifstream input(file.c_str());
    string number;
    string theme;
    string name;
    unsigned int minifigs;
    unsigned int parts;
    double price;
    string data;
    int count;
    getline(input, content);
    if (input.is_open()) {
        while(getline(input, content)) {
            istringstream contentStream(content);
            count = 0;
            while(getline(contentStream, data, ',')) {
                if (count == 0) {
                    number = data;
                } else if (count == 1) {
                    theme = data;
                } else if (count == 2) {
                    name = data;
                } else if (count == 3) {
                    minifigs = static_cast<unsigned int>(stoi(data));
                } else if (count == 4) {
                    parts = static_cast<unsigned int>(stoi(data));
                } else if (count == 5) {
                    price = stod(data);
                }
                ++count;
            }
            list->emplace_back(number, theme, name, minifigs, parts, price);
        }
    }
}

// Destructor
LegoSetList::~LegoSetList() {
    delete list;
}

// Helper Functions:

bool inString (string str, string toCompare) {
    string::size_type strSize = str.size();
    string::size_type toCompareSize = toCompare.size();
    if (strSize < toCompareSize) {
        return false;
    }
    string::size_type j;
    for (string::size_type i = 0; i != strSize - toCompareSize + 1; ++i) {
        j = 0;
        while (j < toCompareSize && toCompare[j] == str[i+j]) {
            ++j;
        }
        if (j == toCompareSize) {
            return true;
        }
    }
    return false;
}

void SearchPrinter(LegoSet legoset) {
    cout << legoset.number << " " << legoset.name << " $" << legoset.price << endl;
}

void PrintSetData(LegoSet legoset) {
    cout << "Name: " << legoset.name << endl;
    cout << "Number: " << legoset.number << endl;
    cout << "Theme: " << legoset.theme << endl;
    cout << "Price: $" << legoset.price << endl;
    cout << "Minifigures: " << legoset.minifigs << endl;
    cout << "Piece count: " << legoset.parts << endl;
}




// Methods
void LegoSetList::MostExpensive(bool helper) {
    LegoSet maxLegoSet = (*list)[0];
    for (LegoSet legoset : *list) {
        if (legoset.price > maxLegoSet.price) {
            maxLegoSet = legoset;
        }
    }
    if (!helper)
        cout << "The most expensive set is:" << endl;
    PrintSetData(maxLegoSet);
}

void LegoSetList::LeastExpensive() {
    LegoSet minLegoSet = (*list)[0];
    for (LegoSet legoset : *list) {
        if (legoset.price < minLegoSet.price) {
            minLegoSet = legoset;
        }
    }
    PrintSetData(minLegoSet);
}

void LegoSetList::LargestPieceCount(bool helper) {
    LegoSet maxLegoSet = (*list)[0];
    for (LegoSet legoset : *list) {
        if (legoset.parts > maxLegoSet.parts) {
            maxLegoSet = legoset;
        }
    }
    if (!helper)
        cout << "The set with the highest parts count:" << endl;
    PrintSetData(maxLegoSet);
}

void LegoSetList::NameSearch(string name) {
    bool found = false;
    bool first = true;
    for (LegoSet legoset: *list) {
        if (first && inString(legoset.name, name)) {
            cout << "Sets matching \"" << name <<"\":" << endl;
            SearchPrinter(legoset);
            found = true;
            first = false;
        } else if (inString(legoset.name, name)) {
            SearchPrinter(legoset);
            found = true;
        }
    }
    if (!found) {
        cout << "No sets found matching that search term" << endl; 
    }
}

void LegoSetList::ThemeSearch(string theme) {
    cout << "Sets matching \"" << theme <<"\":";
    bool found = false;
    for (LegoSet legoset: *list) {
        if (inString(legoset.theme, theme)) {
            SearchPrinter(legoset);
            found = true;
        }
    }
    if (!found) {
        cout << "No sets found matching that search term" << endl; 
    }
}

void LegoSetList::PartCount() {
    unsigned int averagePartCount = 0;
    for (LegoSet legoset: *list) {
        averagePartCount += legoset.parts;
    }
    averagePartCount /= list->size();
    cout << "Average part count for " << list->size() << " sets: " << averagePartCount << endl;
}

void LegoSetList::AvgPrice() {
    double averagePartCount = 0;
    for (LegoSet legoset: *list) {
        averagePartCount += legoset.price;
    }
    averagePartCount /= static_cast<double>(list->size());
    cout << "Average price for " << list->size() << " sets: $" << averagePartCount << endl;
}

void LegoSetList::Price() {
    AvgPrice();
    cout << endl;
    cout << "Least expensive set:" << endl;
    LeastExpensive();
    cout << endl;
    cout << "Most expensive set:" << endl;
    MostExpensive(true);
}

void LegoSetList::MostMinifig() {
    LegoSet maxLegoSet = (*list)[0];
    for (LegoSet legoset : *list) {
        if (legoset.minifigs > maxLegoSet.minifigs) {
            maxLegoSet = legoset;
        }
    }
    PrintSetData(maxLegoSet);
}

void LegoSetList::AvgMinifig() {
    unsigned int averageMinifig = 0;
    for (LegoSet legoset: *list) {
        averageMinifig += legoset.minifigs;
    }
    averageMinifig /= list->size();
    cout << "Average number of minifigures: " << averageMinifig << endl;
}


void LegoSetList::Minifig() {
    AvgMinifig();
    cout << "Set with the most minifigures:" << endl;
    MostMinifig();
}

void LegoSetList::Total() {
    double price = 0;
    unsigned int parts = 0;
    unsigned int minifigs = 0;
    for (LegoSet legoset : *list) {
        price += legoset.price;
        parts += legoset.parts;
        minifigs += legoset.minifigs;
    }
    cout << "If you bought one of everything..." << endl;
    cout << "It would cost: $" << price << endl;
    cout << "You would have " << parts << "pieces in your collection" << endl;
    cout << "You would have an army of " << minifigs << "minifigures!" << endl;
}

unsigned int LegoSetList::GetSetCount() {
    return list->size();
}