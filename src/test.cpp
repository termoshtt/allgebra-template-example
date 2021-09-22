#include <iostream>

int main() {
    #pragma omp parallel for
    for(size_t i = 0; i < 4; i++) {
        std::cout << "Hello Container!" << std::endl;
    }
    return 0;
}