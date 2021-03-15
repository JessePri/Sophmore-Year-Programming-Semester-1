#ifndef LEGO_SET_LIST
#define LEGO_SET_LIST
#include <vector>
#include <string>

class LegoSetList {
public:
    struct LegoSet {

        // Constructors and variables
        LegoSet() = delete;
        LegoSet(std::string setNumber, std::string setTheme, std::string setName, unsigned int setMinifigs, unsigned int setParts, double setPrice):
            number(setNumber), theme(setTheme), name(setName), minifigs(setMinifigs), parts(setParts), price(setPrice) {}

        std::string number;
        std::string theme;
        std::string name;
        unsigned int minifigs;
        unsigned int parts;
        double price;
    };
    // Constructors, copy assignment, and destructors
    LegoSetList() {
        list = new std::vector<LegoSet>;
    }

    LegoSetList(std::vector<std::string> files);
    LegoSetList(const LegoSetList& list) = delete;
    const LegoSetList& operator=(const LegoSetList& list) = delete;
    ~LegoSetList();

    // Methods
    void MostExpensive(bool helper);
    void LeastExpensive();
    void MostMinifig();
    void LargestPieceCount(bool helper);
    void NameSearch(std::string name);
    void ThemeSearch(std::string theme);
    void PartCount();
    void AvgPrice();
    void Price();
    void AvgMinifig();
    void Minifig();
    void Total();
    void read(std::string file);
    unsigned int GetSetCount();
private:
    std::vector<LegoSet>* list;
};




#endif