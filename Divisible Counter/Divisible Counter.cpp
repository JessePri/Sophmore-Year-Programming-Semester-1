#include <iostream>
#include <array>

using std::array;
using std::cout;
using std::endl;

unsigned int GetDivisible(array<unsigned int, 2> bounds, unsigned int num) {
    unsigned int count = 0;
    for (; bounds[0] <= bounds[1]; ++bounds[0]) {
        if (bounds[0] % num == 0) {
            ++count;
        }
    }
    return count;
}

int main() {
    array<unsigned int, 2> bounds = {1000,9999};
    cout << GetDivisible(bounds, 56) << endl;
}

