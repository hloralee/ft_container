
# include "check/3/containers/vector.hpp"
# include <iostream>
# include <vector>


int main() {
    std::vector<int> a(20, 1);

    std::cout << "Длина а = " << a.size() << "\n";
    std::cout << "Емкость а = " << a.capacity() << "\n";
}
