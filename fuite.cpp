#include <iostream>
int main() {
    for (int i = 0; i < 1000; ++i) {
        int* p = new int(42);
        delete p;
    }
    std::cout << "fini, sans fuite" << std::endl;
    return 0;
}
