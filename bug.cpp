#include <vector>
#include <iostream>
int main() {
    std::vector<int> v = {1, 2, 3};
    if (v.size() > 10) {
        std::cout << v[10] << std::endl;
    } else {
        std::cout << "indice hors bornes, taille=" << v.size() << std::endl;
    }
    return 0;
}
