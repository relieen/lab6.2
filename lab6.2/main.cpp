#include <iostream>
#include <bitset> 
#include <type_traits>
#include <windows.h>

template <typename T>
class Checksum {
public:
    static int calculate(T value) {
        std::bitset<sizeof(T) * 8> bits(*reinterpret_cast<unsigned long long*>(&value));

        return bits.count();
    }
};

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int intValue = 42;
    double doubleValue = 3.14;

    cout << "Контрольна сума для int: " << Checksum<int>::calculate(intValue) << endl;
    cout << "Контрольна сума для double: " << Checksum<double>::calculate(doubleValue) << endl;

    return 0;
}
