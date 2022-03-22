
# include "check/3/containers/vector.hpp"
# include <iostream>
# include <vector>
# include <iterator>


int main() {
    std::vector<int> a(10, 1);
    {
    std::vector<int>::iterator b = a.begin();
    std::vector<int>::iterator e = a.end();
    while (b != e)
        std::cout << e-b << ": " << *b++ << "\n";}
    std::cout << "Size is " << a.size() << "\n";
    std::cout << "Capacity is " << a.capacity() << "\n";

    a.assign(5, 2);
        std::vector<int>::iterator b = a.begin();
        std::vector<int>::iterator e = a.end();
        while (b != e)
            std::cout << e-b << ": " << *b++ << "\n";
    std::cout << "Size is " << a.size() << "\n";
    std::cout << "Capacity is " << a.capacity() << "\n";

   // a.reserve(10);
    //std::vector<int>::iterator b = a.begin();
    //std::vector<int>::iterator e = a.end();

    //std::cout << "Size is " << a.size() << "\n";
    //std::cout << "Capacity is " << a.capacity() << "\n";

    //while (b != e) {
    //    std::cout << e-b << ": " << *b++ << "\n";
    //}
}
