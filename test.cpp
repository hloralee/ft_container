
# include "check/3/containers/vector.hpp"
# include <iostream>
# include <vector>


int main() {
    std::vector<int> a;

    for (int i = 0; i < 5; i++) {
        a.push_back(i);
    }

    std::vector<int>::const_iterator it = a.begin();
    std::vector<int>::iterator at = a.end();

    int iii = 0;

    while (it != at){
        std::vector<int>::iterator con(it);
        std::cout << it[iii] << "\n";
        std::cout << *con << "\n";
        it++;
    }

}
